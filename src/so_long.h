#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
#include <fcntl.h>

typedef struct s_window {
	void	*mlx;
	void	*mlx_window;

}	t_window;

typedef struct s_image {
	void	*texture;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		pos_x;
	int		pos_y;

}	t_image;

typedef struct s_textures {
	char	*colectables;
	char	*player;
	char	*floor;
	char	*enemy;
	char	*wall;
	char	*exit;

	int		img_width;
	int		img_height;

}	t_textures;

typedef struct s_player {
	int	x;
	int	y;
	int moves;

}	t_player;

typedef struct s_counter
{
	int	player;
	int	exit;
	int collector;
	int enemy;
	int wall;
	int floor;

}	t_counter;

typedef struct s_map
{
	char	**matrix;
	int		max_x;
	int		max_y;

}	t_map;

typedef struct s_game
{
	t_window	window;
	t_image		image;
	t_textures	textures;
	t_player	player;
	t_counter	counter;
	t_map		map;

}	t_game;

t_counter	inic_counter();
t_map 		render_map();
t_window	render_window(t_game game);
t_image		render_image();
t_textures	render_textures();

int	read_map_file(char *map_path, t_game *game);
int	printing_textures(t_game *game);

#endif