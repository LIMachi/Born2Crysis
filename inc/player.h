#ifndef PLAYER_H
# define PLAYER_H

# include <inventory.h>

# include "world.h"
# include "camera.h"

# define DEFAULT_MAX_WALK_SPEED	0.15
# define DEFAULT_MAX_RUN_SPEED	0.4
# define DEFAULT_MAX_LIFE		100

# define DEFAULT_FRICTION		0.90

# define DEFAULT_JUMP_FORCE		0.45

# define ACC_GRAVITY			0
# define ACC_PLAYER_WALK		0.05
# define ACC_PLAYER_JUMP		2
# define ACC_MODIFIER			3
# define ACCELERATIONS			4

# define CAMERA_HEIGHT		4

typedef struct	s_player_stats
{
	int			life;
	int			max_life;
	int			armor;
	int			stamina;
	int			max_stamina;
	int			kill_count;
	int			score;
	char		script_data[64];
}				t_player_stats;

typedef struct	s_player
{
	double			pos[3];
	double			velocity[3];
	double			acceleration[ACCELERATIONS][3];
	double			max_speed;
	t_bool			on_ground;
	t_bool			is_running;
	double			direction[3];
	int				sector;
	t_inventory		inventory;
	t_player_stats	stats;
}				t_player;

void			init_player(t_player *p);
void			update_player_sector(t_player *p, t_world *world);

#endif
