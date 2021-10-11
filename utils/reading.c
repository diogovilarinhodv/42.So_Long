/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:40:42 by dpestana          #+#    #+#             */
/*   Updated: 2021/10/11 15:54:17 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

static char	*get_first_line(char *map_path, t_game *g, int *fd)
{
	char	*line;

	*fd = open(map_path, O_RDONLY);
	if (*fd == -1)
		error_open_file(fd, g);
	line = get_next_line(*fd);
	if (line == NULL)
		error_first_line(fd, g);
	g->map.max_x = ft_strlen(line) - 1;
	return (line);
}

static void	set_new_line_in_map(t_game *g, char *line, int *fd)
{
	char	**row;
	int		cnt;

	cnt = 0;
	row = malloc((g->map.max_y + 1) * sizeof(char **));
	if (row == NULL)
		error_alloc_mem(fd, g);
	while (cnt < g->map.max_y)
	{
		row[cnt] = g->map.matrix[cnt];
		cnt++;
	}
	row[cnt] = line;
	if (g->map.matrix != NULL)
		free(g->map.matrix);
	g->map.matrix = row;
	g->map.max_y++;
}

void	read_map_file(char *map_path, t_game *g)
{
	int		fd;
	char	*line;

	line = get_first_line(map_path, g, &fd);
	while (line != NULL)
	{
		set_new_line_in_map(g, line, &fd);
		if (g->map.max_x != ft_strlen(line) - 1)
			error_line_longer(g);
		line = get_next_line(fd);
	}
	close(fd);
	if (g->map.max_x == g->map.max_y)
		error_square_map(g);
}
