/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kf_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 13:03:10 by mfischer          #+#    #+#             */
/*   Updated: 2019/07/14 13:08:26 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_funcs.h"

void	kf_jump(void *param)
{
	t_e		*e;

	e = param;
	if (e->main_player.on_ground)
		vec3vec3_add(e->main_player.velocity, e->main_player.acceleration[ACC_PLAYER_JUMP], e->main_player.velocity);
}
