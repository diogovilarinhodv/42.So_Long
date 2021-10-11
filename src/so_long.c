/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:38:30 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/11 13:21:29 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;

	g.count = inic_counter();
	g.map = render_map();
	if (argc != 2)
		error_args();
	read_map_file(argv[argc - 1], &g);
	g.win = render_window(g);
	g.textures = render_textures(g);
	printing_textures(&g);
	mlx_loop_hook(g.win.mlx, enemy_events, &g);
	mlx_hook(g.win.mlx_win, KEY_PRESS, KEY_PRESS_MASK << 0, key_hook, &g);
	mlx_hook(g.win.mlx_win, X_BUTTON, KEY_PRESS_MASK << 0, click_to_close, &g);
	mlx_string_put(g.win.mlx, g.win.mlx_win, 0, 0, 255, "Moves: 0");
	mlx_loop(g.win.mlx);
	game_over(&g, 1, 1, 0);
	return (0);
}
