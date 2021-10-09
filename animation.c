/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:27:41 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/09 19:47:39 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

static void	set_texture(t_game *g, char *t, int y, int x)
{
	mlx_put_image_to_window(g->win.mlx, g->win.mlx_win, t, x, y);
}

static void	enemy_moving(t_game *g, int x, int y)
{
	char coords_right;
	char coords_left;
	char coords_down;
	char coords_up;

	coords_right = g->map.matrix[y][x + 1];
	coords_left = g->map.matrix[y][x - 1];
	coords_down = g->map.matrix[y + 1][x];
	coords_up = g->map.matrix[y - 1][x];
	if (coords_right == '0' || coords_right == 'P')
	{	
		set_texture(g, g->textures.floor, y * 100, x * 100);
		set_texture(g, g->textures.enemy, y * 100, (x + 1) * 100);
		if (g->map.matrix[y][x + 1] == 'P')
			game_over(g, 1, 1, 0);
		g->map.matrix[y][x] = '0';
		g->map.matrix[y][x + 1] = 'X';
	}
	else if (coords_left == '0' || coords_left == 'P')
	{
		set_texture(g, g->textures.floor, y * 100, x * 100);
		set_texture(g, g->textures.enemy, y * 100, (x - 1) * 100);
		if (g->map.matrix[y][x - 1] == 'P')
			game_over(g, 1, 1, 0);
		g->map.matrix[y][x] = '0';
		g->map.matrix[y][x - 1] = 'X';
	}
	else if (coords_down == '0' || coords_down == 'P')
	{
		set_texture(g, g->textures.floor, y * 100, x * 100);
		set_texture(g, g->textures.enemy, (y + 1) * 100, x * 100);
		if (g->map.matrix[y + 1][x] == 'P')
			game_over(g, 1, 1, 0);
		g->map.matrix[y][x] = '0';
		g->map.matrix[y + 1][x] = 'X';
	}
	else if (coords_up == '0' || coords_up == 'P')
	{
		set_texture(g, g->textures.floor, y * 100, x * 100);
		set_texture(g, g->textures.enemy, (y - 1) * 100, x * 100);
		if (g->map.matrix[y - 1][x] == 'P')
			game_over(g, 1, 1, 0);
		g->map.matrix[y][x] = '0';
		g->map.matrix[y - 1][x] = 'X';
	}
}

static char	*anim(t_game *g)
{
	char	*enemy_texture;

	enemy_texture = g->textures.enemy;
	if (g->textures.animation == 0)
		enemy_texture = g->textures.enemy;
	else if (g->textures.animation == 1)
		enemy_texture = g->textures.enemy_m1;
	else if (g->textures.animation == 2)
		enemy_texture = g->textures.enemy_m2;
	else if (g->textures.animation == 3)
		enemy_texture = g->textures.enemy_m3;
	else if (g->textures.animation == 4)
	{
		g->textures.animation = 0;
		enemy_texture = g->textures.enemy;
	}
	g->textures.animation++;
	return (enemy_texture);
}

void	get_animation(t_game *g)
{
	int		x;
	int		y;
	int		w;
	int		h;

	x = 0;
	y = 0;
	while (g->map.max_y > y)
	{
		w = x * 100;
		h = y * 100;
		if (g->map.matrix[y][x] == 'X')
		{
			mlx_put_image_to_window(g->win.mlx, g->win.mlx_win, anim(g), w, h);
			if (g->textures.animation == 1)
				enemy_moving(g, x , y);
		}
		if (!(g->map.max_x > x))
		{
			y++;
			x = 0;
		}
		x++;
	}
}
