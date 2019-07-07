/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 23:33:23 by mfischer          #+#    #+#             */
/*   Updated: 2019/07/07 23:22:21 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void		render_sector(t_sector *sector, t_camera *cam, SDL_Surface *surface, t_mesh *portal)
{
	int i;
	t_sector	*next_sect;

	i = -1;
	if (portal)
		portal_cull(sector->mesh, sector->meshnum, portal, cam->pos);
	while (++i < sector->meshnum)
	{
		if (!portal || sector->mesh[i].active)
			render_mesh(&sector->mesh[i], cam, surface, &sector->lights);
	}
 	i = -1;
	
	//HANDLE OBJECT RENDERING
	
	while ((next_sect = sector_queue_pop()))
		render_sector(portal, cam, surface);
}
