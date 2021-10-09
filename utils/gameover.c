/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:40:12 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/09 18:26:40 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

static void	clean_map(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->map.max_y)
	{
		free(g->map.matrix[i]);
		i++;
	}
	free(g->map.matrix);
}

static void	clean_textures(t_game *g)
{
	mlx_destroy_image(g->win.mlx, g->textures.wall);
	mlx_destroy_image(g->win.mlx, g->textures.floor);
	mlx_destroy_image(g->win.mlx, g->textures.player);
	mlx_destroy_image(g->win.mlx, g->textures.collect);
	mlx_destroy_image(g->win.mlx, g->textures.exit);
	mlx_destroy_image(g->win.mlx, g->textures.enemy);
	mlx_destroy_image(g->win.mlx, g->textures.enemy_m1);
	mlx_destroy_image(g->win.mlx, g->textures.enemy_m2);
	mlx_destroy_image(g->win.mlx, g->textures.enemy_m3);
}

static void	clean_window(t_game *g)
{
	mlx_destroy_window(g->win.mlx, g->win.mlx_win);
}

void	game_over(t_game *g, int clear_window, int clear_map, int error)
{
	if (clear_window == 1)
	{
		clean_textures(g);
		clean_window(g);
	}
	if (clear_map == 1)
		clean_map(g);
	if (error == 1)
		exit(1);
	exit(0);
}
