/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_to_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 00:04:36 by mfischer          #+#    #+#             */
/*   Updated: 2019/07/27 17:09:08 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	perspective_divide(t_polygon *p, int width, int height)
{
// <<<<<<< HEAD
	p->v01.c2.vec2d = vec2scalar_divide(p->v01.c2.vec2d, p->v01.a[2]);
	p->v12.c2.vec2d = vec2scalar_divide(p->v12.c2.vec2d, p->v12.a[2]);
	p->v20.c2.vec2d = vec2scalar_divide(p->v20.c2.vec2d, p->v20.a[2]);
	p->v01.a[0] = (p->v01.a[0] + 1.0) * (double)(width / 2.0);
	p->v12.a[0] = (p->v12.a[0] + 1.0) * (double)(width / 2.0);
	p->v20.a[0] = (p->v20.a[0] + 1.0) * (double)(width / 2.0);
	p->v01.a[1] = (p->v01.a[1] + 1.0) * (double)(height / 2.0);
	p->v12.a[1] = (p->v12.a[1] + 1.0) * (double)(height / 2.0);
	p->v20.a[1] = (p->v20.a[1] + 1.0) * (double)(height / 2.0);
	p->v01_uv = vec2scalar_divide(p->v01_uv, - p->v01.a[2]);
	p->v12_uv = vec2scalar_divide(p->v12_uv, - p->v12.a[2]);
	p->v20_uv = vec2scalar_divide(p->v20_uv, - p->v20.a[2]);
	// p->v01.a[2] = -1.0 / p->v01.a[2];
	// p->v12.a[2] = -1.0 / p->v12.a[2];
	// p->v20.a[2] = -1.0 / p->v20.a[2];
// =======
// 	vec2scalar_divide(p->v01, p->v01[2], p->v01);
// 	vec2scalar_divide(p->v12, p->v12[2], p->v12);
// 	vec2scalar_divide(p->v20, p->v20[2], p->v20);
// 	p->v01[0] = (p->v01[0] + 1.0) * (double)(width / 2.0);
// 	p->v12[0] = (p->v12[0] + 1.0) * (double)(width / 2.0);
// 	p->v20[0] = (p->v20[0] + 1.0) * (double)(width / 2.0);
// 	p->v01[1] = (p->v01[1] + 1.0) * (double)(height / 2.0);
// 	p->v12[1] = (p->v12[1] + 1.0) * (double)(height / 2.0);
// 	p->v20[1] = (p->v20[1] + 1.0) * (double)(height / 2.0);
// 	vec2scalar_divide(p->v01_uv, -p->v01[2], p->v01_uv);
// 	vec2scalar_divide(p->v12_uv, -p->v12[2], p->v12_uv);
// 	vec2scalar_divide(p->v20_uv, -p->v20[2], p->v20_uv);
	p->v_light.a[0] /= -p->v01.a[2];
	p->v_light.a[1] /= -p->v12.a[2];
	p->v_light.a[2] /= -p->v20.a[2];
	p->v01.a[2] = -1.0 / p->v01.a[2];
	p->v12.a[2] = -1.0 / p->v12.a[2];
	p->v20.a[2] = -1.0 / p->v20.a[2];
// >>>>>>> dev
}

void		view_to_projection(t_polygon *p, int count, t_mat4d proj_mat, SDL_Surface *surface)
{
	int i;

	i = -1;
	while (++i < count)
	{
		if (p[i].tex_id == -1)
			continue ;
		p[i].v01 = mat4vec4_multiply(proj_mat, p[i].v01);
		p[i].v12 = mat4vec4_multiply(proj_mat, p[i].v12);
		p[i].v20 = mat4vec4_multiply(proj_mat, p[i].v20);
		perspective_divide(&p[i], surface->w, surface->h);
		
	}
}
