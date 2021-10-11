/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:53:07 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/11 15:03:36 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/so_long.h"

// [reading.c]
void	error_open_file(int *fd, t_game *g)
{
	close(*fd);
	write(1, "Error\n", 7);
	write(1, "Open file failed\n", 18);
	game_over(g, 0, 0, 1);
}

// [reading.c]
void	error_first_line(int *fd, t_game *g)
{
	close(*fd);
	write(1, "Error\n", 7);
	write(1, "First line of file error!\n", 27);
	game_over(g, 0, 0, 1);
}

// [reading.c]
void	error_alloc_mem(int *fd, t_game *g)
{
	close(*fd);
	write(1, "Error\n", 7);
	write(1, "Memory allocation failed\n", 26);
	if (g->map.matrix != NULL)
		game_over(g, 0, 1, 1);
	else
		game_over(g, 0, 0, 1);
}

// [reading.c]
void	error_line_longer(t_game *g)
{
	write(1, "Error\n", 7);
	write(1, "Line longer than others\n", 25);
	game_over(g, 0, 1, 1);
}

// [reading.c]
void	error_square_map(t_game *g)
{
	write(1, "Error\n", 7);
	write(1, "Square map not valid\n", 22);
	game_over(g, 0, 1, 1);
}
