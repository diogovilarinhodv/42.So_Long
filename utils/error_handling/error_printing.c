/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:53:10 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/09 18:17:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/so_long.h"

// [printing_textures.c]
void	error_invalid_map_char(t_game *g)
{
	write(1, "Error\n", 7);
	write(1, "Invalid char finded inside map\n", 32);
	game_over(g, 1, 1, 1);
}

// [printing_textures.c]
void	error_too_many_entities(t_game *g)
{
	write(1, "Error\n", 7);
	if (g->count.player != 1)
		write(1, "Invalid quantity of players\n", 29);
	if (g->count.exit != 1)
		write(1, "Invalid quantity of exits\n", 27);
	if (g->count.collect < 1)
		write(1, "Invalid quantity of collectables\n", 34);
	game_over(g, 1, 1, 1);
}

// [printing_textures.c]
void	error_horiz_wall(t_game *g)
{
	write(1, "Error\n", 7);
	write(1, "Invalid char finded at horizontal border\n", 42);
	game_over(g, 1, 1, 1);
}

// [printing_textures.c]
void	error_verti_wall(t_game *g)
{
	write(1, "Error\n", 7);
	write(1, "Invalid char finded at vertical border\n", 40);
	game_over(g, 1, 1, 1);
}
