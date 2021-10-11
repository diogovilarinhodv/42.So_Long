/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:06:44 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/11 13:03:19 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

static void	set_texture(t_game *g, char *t, int y, int x)
{
	mlx_put_image_to_window(g->win.mlx, g->win.mlx_win, t, x, y);
}

static void	x_mov(t_game *g, int x, int y, int next)
{
	set_texture(g, g->textures.floor, y * 100, x * 100);
	set_texture(g, g->textures.enemy, y * 100, (x + next) * 100);
	if (g->map.matrix[y][x + next] == 'P')
		game_over(g, 1, 1, 0);
	g->map.matrix[y][x] = '0';
	g->map.matrix[y][x + next] = 'X';
}

static void	y_mov(t_game *g, int x, int y, int next)
{
	set_texture(g, g->textures.floor, y * 100, x * 100);
	set_texture(g, g->textures.enemy, (y + next) * 100, x * 100);
	if (g->map.matrix[y + next][x] == 'P')
		game_over(g, 1, 1, 0);
	g->map.matrix[y][x] = '0';
	g->map.matrix[y + next][x] = 'X';
}

void	enemy_moving(t_game *g, int x, int y)
{
	char	coords_right;
	char	coords_left;
	char	coords_down;
	char	coords_up;

	coords_right = g->map.matrix[y][x + 1];
	coords_left = g->map.matrix[y][x - 1];
	coords_down = g->map.matrix[y + 1][x];
	coords_up = g->map.matrix[y - 1][x];
	if (coords_right == '0' || coords_right == 'P')
		x_mov(g, x, y, 1);
	else if (coords_left == '0' || coords_left == 'P')
		x_mov(g, x, y, -1);
	else if (coords_down == '0' || coords_down == 'P')
		y_mov(g, x, y, 1);
	else if (coords_up == '0' || coords_up == 'P')
		y_mov(g, x, y, -1);
}
