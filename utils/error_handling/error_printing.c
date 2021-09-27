/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:53:10 by dpestana          #+#    #+#             */
/*   Updated: 2021/09/27 12:53:15 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/so_long.h"

// [printing_textures.c] 
int	map_char_invalid(t_game *g)
{
	write(1, "Error\n", 7);
	write(1, "Invalid char finded inside map\n", 32);
	return (game_over(g));
}

// [printing_textures.c] 
int	too_much_entities(t_game *g)
{
	if (g->count.player != 1 || g->count.exit != 1)
	{
		write(1, "Error\n", 7);
		if (g->count.player != 1)
			write(1, "Invalid quantity of players\n", 29);
		if (g->count.exit != 1)
			write(1, "Invalid quantity of exits\n", 27);
		return (game_over(g));
	}
	return (0);
}

// [printing_textures.c] 
int	wall_error(t_game *g, int y, int x)
{
	char	coords;

	coords = g->map.matrix[y][x];
	if ((y == 0 || y == (g->map.max_y - 1)) && coords != '1')
	{
		write(1, "Error\n", 7);
		write(1, "Invalid char finded at horizontal border\n", 40);
		return (game_over(g));
	}
	else if ((x == 0 || x == (g->map.max_x - 1)) && coords != '1')
	{
		write(1, "Error\n", 7);
		write(1, "Invalid char finded at vertical border\n", 42);
		return (game_over(g));
	}
	return (0);
}
