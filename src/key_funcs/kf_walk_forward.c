/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kf_walk_forward.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:34:08 by mfischer          #+#    #+#             */
/*   Updated: 2019/07/20 16:28:10 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"

void	kf_walk_forward(void *param)
{
	t_e		*e;

	e = param;
	if (e->main_player.on_ground)
	{
		e->main_player.velocity = vec3vec3_substract(e->main_player.velocity, vec3scalar_multiply(e->main_player.direction, ACC_PLAYER_WALK));
	}
}
