/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:27:41 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/09 18:28:30 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

char	*anim(t_game *g)
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
		g->textures.animation = 0;
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
			mlx_put_image_to_window(g->win.mlx, g->win.mlx_win, anim(g), w, h);
		if (!(g->map.max_x > x))
		{
			y++;
			x = 0;
		}
		x++;
	}
}
