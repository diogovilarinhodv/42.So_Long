/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:40:09 by dpestana          #+#    #+#             */
/*   Updated: 2021/09/27 12:47:03 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

static void	set_texture(t_game *g, char *texture, int x, int y)
{
	int	width;
	int	height;

	width = x * 100;
	height = y * 100;
	mlx_put_image_to_window(g->win.mlx, g->win.mlx_win, texture, width, height);
}

static void	set_count(t_game *g, char ch, int x, int y)
{
	if (ch == 'P')
	{
		g->count.player++;
		g->player.x = x;
		g->player.y = y;
	}
	else if (ch == 'E')
		g->count.exit++;
	else if (ch == 'C')
		g->count.collect++;
	else if (ch == '1')
		g->count.wall++;
	else if (ch == '0')
		g->count.floor++;
	else if (ch == 'X')
		g->count.enemy++;
}

static int	get_texture(t_game *g, char ch, int x, int y)
{
	if (ch == 'P')
		set_texture(g, g->textures.player, x, y);
	else if (ch == 'E')
		set_texture(g, g->textures.exit, x, y);
	else if (ch == 'C')
		set_texture(g, g->textures.collect, x, y);
	else if (ch == '1')
		set_texture(g, g->textures.wall, x, y);
	else if (ch == '0')
		set_texture(g, g->textures.floor, x, y);
	else if (ch == 'X')
		set_texture(g, g->textures.enemy, x, y);
	else
		return (1);
	set_count(g, ch, x, y);
	return (0);
}

int	printing_textures(t_game *g)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < g->map.max_y)
	{
		while (x < g->map.max_x)
		{
			if (get_texture(g, g->map.matrix[y][x], x, y) == 1)
				return (map_char_invalid(g));
			if (wall_error(g, y, x) == 1)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	if (too_much_entities(g))
		return (1);
	return (0);
}
