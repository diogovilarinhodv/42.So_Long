/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:38:48 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/09 18:40:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../gnl/get_next_line.h"
# include <fcntl.h>

// Macros masks
# define KEY_PRESS_MASK 1L
# define KEY_PRESS 02

// Macros keys
# define X_BUTTON 17
# define KEY_ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

// Structers
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
	int		delay;

	int		width;
	int		height;

}	t_textures;

typedef struct s_player {
	int	x;
	int	y;

}	t_player;

typedef struct s_counter
{
	int	player;
	int	exit;
	int	collect;
	int	enemy;
	int	wall;
	int	floor;
	int	moves;

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

// Structers
t_counter	inic_counter(void);
t_map		render_map(void);
t_window	render_window(t_game g);
t_textures	render_textures(t_game g);

// Utils functions
void		read_map_file(char *map_path, t_game *g);
void		printing_textures(t_game *g);
void		move(t_game *g, int inc_x, int inc_y);
void		get_animation(t_game *g);

// Ending game correctly functions
void		game_over(t_game *g, int clear_window, int clear_map, int error);

// Libft stuff
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);

// Events
int			click_to_close(t_game *g);
int			render_next_frame(t_game *g);
int			key_hook(int key_press, t_game *g);

// Error handling
void		error_args(void);

// Error handling reading
void		error_open_file(int *fd, t_game *g);
void		error_first_line(int *fd, t_game *g);
void		error_alloc_mem(int *fd, t_game *g);
void		error_square_map(t_game *g);

// Error handling printing
void		error_invalid_map_char(t_game *g);
void		error_too_many_entities(t_game *g);
void		error_horiz_wall(t_game *g);
void		error_verti_wall(t_game *g);

#endif