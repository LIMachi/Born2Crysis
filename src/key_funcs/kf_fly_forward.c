/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kf_fly_forward.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:19:31 by mfischer          #+#    #+#             */
/*   Updated: 2019/09/03 00:04:46 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"

void	kf_fly_forward(void *param)
{
	t_e		*e;

	e = param;
	if (e->editor.item_placer && e->editor.is_modified && e->input_map.
	keys[SDL_SCANCODE_LSHIFT].active)
	{
		e->editor.item_placer->matrix = mat4_translate(
			e->editor.item_placer->matrix, 0, 0, ROTATE_SPEED);
	}
	else
	{
		e->editor.editor_cam.pos = vec3vec3_substract(e->editor.editor_cam.pos,
		vec3scalar_multiply(e->editor.editor_cam.view_dir, FLY_SPEED));
	}
}
