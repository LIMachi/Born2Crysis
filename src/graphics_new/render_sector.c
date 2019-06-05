/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 23:33:23 by mfischer          #+#    #+#             */
/*   Updated: 2019/06/05 23:17:42 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void		render_sector(	t_sector *sector, t_libui_window *win, t_camera *cam)
{
	t_sector	*sector;
	int			i;
	
	i = -1;
	if (!(sector = get_sector(sector_id, world)))
		return ;
	while (++i < sector->objectnum)
		//render objects
}