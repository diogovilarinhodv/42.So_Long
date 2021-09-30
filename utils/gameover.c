/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:40:12 by dpestana          #+#    #+#             */
/*   Updated: 2021/09/30 11:24:00 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	game_over(t_game *g)
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
	mlx_destroy_window(g->win.mlx, g->win.mlx_win);
	free(g->map.matrix);
	exit(1);
	return (1);
}
