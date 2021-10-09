/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:27:34 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/09 18:29:11 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	click_to_close(t_game *g)
{
	game_over(g, 1, 1, 0);
	return (0);
}

int	render_next_frame(t_game *g)
{
	if (g->textures.delay == 5000)
		get_animation(g);
	g->textures.delay++;
	if (g->textures.delay == 10000)
		g->textures.delay = 0;
	return (0);
}

int	key_hook(int key_press, t_game *g)
{
	if (key_press == KEY_ESC)
		game_over(g, 1, 1, 0);
	else if (key_press == A)
		move(g, 0, -1);
	else if (key_press == S)
		move(g, 1, 0);
	else if (key_press == D)
		move(g, 0, 1);
	else if (key_press == W)
		move(g, -1, 0);
	return (key_press);
}
