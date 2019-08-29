/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfischer <mfischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:12:06 by mfischer          #+#    #+#             */
/*   Updated: 2019/08/29 19:47:05 by mfischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <stdlib.h>

# include <physic.h>

# include "mflib.h"
# include "libui.h"

# include "lights.h"

# include "texture_manager.h"

# define MAX_PORTALS_PER_SECTOR	100
# define D_GRAVITY				1.2
# define GROUND_RATIO			0.8

typedef struct		s_polygon
{
	t_vec4d			v01;
	t_vec4d			v12;
	t_vec4d			v20;
	t_vec3d			normal;
	t_vec2d			v01_uv;
	t_vec2d			v12_uv;
	t_vec2d			v20_uv;
	t_vec3d			v_light;
	int32_t			tex_id;
	int32_t			transparency;
}					t_polygon;

typedef struct		s_mesh
{
	t_polygon		*polygons;
	t_mat4d			matrix;
	int32_t			polygonnum;
	int32_t			sector_id;
	t_vec3d			portal_normal;
	double			radius;
	t_bool			active;
	int32_t			nb_walls;
	int				light_id;
	t_wall			*walls;
}					t_mesh;

typedef struct		s_sector
{
	int32_t				id;
	t_mesh				*mesh;
	t_light_comp		lights;
	int32_t				meshnum;
	t_mesh				*src_portal;
	int32_t				nb_entities;
	t_entity			*entites;
	t_sector_physics	physics;
}					t_sector;

typedef struct		s_world
{
	t_sector		*sectors;
	t_mesh			*skybox;
	int32_t			nb_textures;
	t_texture		*textures;
	int32_t			sectornum;
	t_vec3d			goal_point;
}					t_world;

typedef enum		s_effect
{
	EFF_NOTHING = 0,
	EFF_RESET_JUMP,
	EFF_ACTIVATE_FLY,
	EFF_DEACTIVATE_FLY
}					t_effect;

t_wall				polygon_to_wall(t_polygon poly, t_mat4d mat);
t_polygon			wall_to_polygon(t_wall wall, int tex_id);

int					update_entity(t_world *world, t_entity *ent);

t_bool				init_world(t_world *world);
void				world_destroy(t_world *w);
t_world				*set_world(t_world *world);
t_world				*get_world();
void				init_portals(t_world *world);
void				gen_portal_outline(t_mesh *m);
t_polygon			*set_polygon_buffer(t_polygon *addr, int size);
int32_t				get_polygon_buffer_size();
t_polygon			*get_polygon_buffer();
t_bool    			buffer_increase(size_t size);
t_polygon			*polygon_copy(t_polygon *p);
t_sector			*get_sector(int32_t id, t_world *world);
t_polygon			*load_buffer(t_world *world);
double				get_mesh_radius(t_mesh *mesh);

void				world_add_mesh(t_mesh *mesh, t_world *world, int sector_id);

t_mesh				*mesh_copy(t_mesh *mesh);
int					mesh_delete(t_mesh **meshes, int size, int index);
void				mesh_change_texture(t_mesh *mesh, int32_t id);
void				sector_create(t_world *world);

void				apply_effect(t_entity *e, t_world *w, t_effect effect);
void				mesh_add_physics(t_mesh *mesh);

#endif
