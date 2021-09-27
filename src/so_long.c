/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:38:30 by dpestana          #+#    #+#             */
/*   Updated: 2021/09/27 12:11:38 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key_press, t_game *g)
{
	if (key_press == A)
		move(g, 0, -1);
	else if (key_press == S)
		move(g, 1, 0);
	else if (key_press == D)
		move(g, 0, 1);
	else if (key_press == W)
		move(g, -1, 0);
	else if (key_press == KEY_ESC || key_press == X_BUTTON_EXIT)
		game_over(g);
	return (key_press);
}

int	main(int argc, char **argv)
{
	t_game	g;

	g.count = inic_counter();
	g.map = render_map();
	if (argc != 2)
		return (args_error());
	if (read_map_file(argv[argc - 1], &g))
		return (1);
	g.win = render_window(g);
	g.textures = render_textures(g);
	if (printing_textures(&g) == 1)
		return (1);
	mlx_hook(g.win.mlx_win, KEY_PRESS, KEY_PRESS_MASK << 0, key_hook, &g);
	mlx_string_put(g.win.mlx, g.win.mlx_win, 0, 0, 255, "Moves: 0");
	mlx_loop(g.win.mlx);
	game_over(&g);
	return (0);
}
