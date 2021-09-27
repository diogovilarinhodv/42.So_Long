/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:40:15 by dpestana          #+#    #+#             */
/*   Updated: 2021/09/27 11:08:37 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

static void	move_count(t_game *g)
{
	char	*moves;
	char	*qtd_moves;

	g->player.moves++;
	qtd_moves = ft_itoa(g->player.moves);
	moves = ft_strjoin("Moves: ", qtd_moves);
	mlx_put_image_to_window(g->win.mlx, g->win.mlx_win, g->textures.wall, 0, 0);
	mlx_string_put(g->win.mlx, g->win.mlx_win, 0, 0, 1, moves);
	free(qtd_moves);
	free(moves);
}

static void	set_new_pos(t_game *g, int new_y_pos, int new_x_pos)
{
	char	ch_pos_old;

	ch_pos_old = g->map.matrix[g->player.y][g->player.x];
	if (ch_pos_old == 'P' || ch_pos_old == 'C')
		g->map.matrix[g->player.y][g->player.x] = '0';
	if (new_x_pos != 0)
		g->player.x += new_x_pos;
	else if (new_y_pos != 0)
		g->player.y += new_y_pos;
}

static void	set_texture(t_game *g, int y, int x)
{
	int		px;
	int		py;
	char	*tf;
	char	*tp;

	px = (g->player.x * 100);
	py = (g->player.y * 100);
	tf = g->textures.floor;
	tp = g->textures.player;
	mlx_put_image_to_window(g->win.mlx, g->win.mlx_win, tf, px, py);
	mlx_put_image_to_window(g->win.mlx, g->win.mlx_win, tp, px + x, py + y);
}

void	move(t_game *g, int y, int x)
{
	char	next;

	next = g->map.matrix[g->player.y + y][g->player.x + x];
	if (next == '0' || next == 'C' || (next == 'E' && g->count.collect == 0))
	{
		if (next == 'C')
			g->count.collect--;
		set_texture(g, y * 100, x * 100);
		set_new_pos(g, y, x);
		move_count(g);
		if (next == 'E')
			game_over(g);
	}
	if (next == 'X')
		game_over(g);
}
