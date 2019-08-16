#include <asm.h>

//should be called with head on the first byte of the first argument
int	process_load_op_args(t_process *p, uint8_t nb_args)
{
	size_t	head;
	uint8_t	mask;
	uint8_t	i;

	head = p->registers[ARI_INST_PTR].u;
	i = -1;
	while (++i < nb_args)
	{
		mask = p->code[head] & AL_MASK;
		p->op_args[i].type = p->code[head] & AT_MASK;
		if (mask == AL_MEMORY)
		{
			mask = p->code[head + 1];
			if (mask == AL_IMMEDIATE)
			{
				p->voider[i].u = *(uint64_t *)&p->code[head + 2];
				head += 6;
			}
			else if (mask == AL_REGISTER && p->code[head + 2] <= ARI_INST_PTR)
			{
				p->voider[i] = p->registers[p->code[head + 2]];
				head += 3;
			}
			else
				return (-1);
			p->op_args[i].data = p->voider[i].ptr;
			continue ;
		}
		if (mask == AL_IMMEDIATE)
		{
			p->voider[i].u = *(uint64_t*)&p->code[head + 1];
			p->op_args[i].data = &p->voider[i];
			head += 5;
		}
		else if (mask == AL_REGISTER)
		{
			if ((mask = p->code[head + 1]) > ARI_INST_PTR)
				return (-1);
			p->op_args[i].data = &p->registers[mask];
			head += 2;
		}
		else
			return (-1);
	}
	p->registers[ARI_INST_PTR].u = head;
	return (0);
}
