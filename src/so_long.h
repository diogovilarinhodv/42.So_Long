/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:38:48 by dpestana          #+#    #+#             */
/*   Updated: 2021/09/30 10:17:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../gnl/get_next_line.h"
# include <fcntl.h>

# define KEY_PRESS_MASK 1L
# define KEY_PRESS 02

# define X_BUTTON_EXIT 17
# define KEY_ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_window {
	void	*mlx;
	void	*mlx_win;

}	t_window;

typedef struct s_textures {
	char	*collect;
	char	*player;
	char	*floor;
	char	*enemy;
	char	*wall;
	char	*exit;
	char	*enemy_m1;
	char	*enemy_m2;
	char	*enemy_m3;
	int		animation;

	int		width;
	int		height;

}	t_textures;

typedef struct s_player {
	int	x;
	int	y;
	int	moves;

}	t_player;

typedef struct s_counter
{
	int	player;
	int	exit;
	int	collect;
	int	enemy;
	int	wall;
	int	floor;

}	t_counter;

typedef struct s_map
{
	char	**matrix;
	int		max_x;
	int		max_y;

}	t_map;

typedef struct s_game
{
	t_window	win;
	t_textures	textures;
	t_player	player;
	t_counter	count;
	t_map		map;

}	t_game;

t_counter	inic_counter(void);
t_map		render_map(void);
t_window	render_window(t_game g);
t_textures	render_textures(t_game g);

int			read_map_file(char *map_path, t_game *g);
int			printing_textures(t_game *g);
void		move(t_game *g, int inc_x, int inc_y);
int			game_over(t_game *g);

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);

int			args_error(void);
int			alloc_mem_error(int *fd, t_game *g);
int			open_file_error(int *fd, t_game *g);
int			square_error(t_game *g);
int			map_char_invalid(t_game *g);
int			too_much_entities(t_game *g);
int			wall_error(t_game *g, int y, int x);

#endif