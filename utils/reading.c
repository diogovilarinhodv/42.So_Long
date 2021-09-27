/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:40:42 by dpestana          #+#    #+#             */
/*   Updated: 2021/09/27 12:56:15 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

static char	*get_first_line(char *map_path, t_game *g, int *fd)
{
	char	*line;

	*fd = open(map_path, O_RDONLY);
	if (*fd == -1)
		return (NULL);
	line = get_next_line(*fd);
	g->map.max_x = ft_strlen(line) - 1;
	return (line);
}

static int	set_new_line_in_map(t_game *g, char *line)
{
	char	**row;
	int		cnt;

	cnt = 0;
	row = malloc((g->map.max_y + 1) * sizeof(char **));
	if (row == NULL)
		return (1);
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
	return (0);
}

int	read_map_file(char *map_path, t_game *g)
{
	int		fd;
	char	*line;

	line = get_first_line(map_path, g, &fd);
	if (line == NULL)
		return (open_file_error(&fd));
	while (line != NULL)
	{
		if (set_new_line_in_map(g, line) == 1)
			return (alloc_mem_error(&fd));
		line = get_next_line(fd);
	}
	close(fd);
	if (square_error(g) == 1)
		return (1);
	return (0);
}
