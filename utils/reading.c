#include "../src/so_long.h"

static char	*get_first_line(char *map_path, t_game *game, int *fd)
{
	char *line;

	*fd = open(map_path, O_RDONLY);
	if (*fd == -1)
		return (NULL);
	line = get_next_line(*fd);
	game->map.max_x = ft_strlen(line);
	return (line);
}

static int	set_new_line_in_map(t_game *game, char *line)
{
	char	**matrix;
	int		cnt;

	cnt = 0;
	matrix = malloc((game->map.max_y + 1) * sizeof(char **));
	if (matrix == NULL)
		return (1);
	while (cnt < game->map.max_y)
	{
		matrix[cnt] = game->map.matrix[cnt];
		cnt++;
	}
	matrix[cnt] = line;
	if (game->map.matrix == NULL)
		free(game->map.matrix);
	game->map.matrix = matrix;
	game->map.max_y++;
	return (0);
}

int			read_map_file(char *map_path, t_game *game)
{
	int		fd;
	char	*line;

	line = get_first_line(map_path, game, &fd);
	if (line == NULL)
		return (1);
	while(line != NULL)
	{
		if (set_new_line_in_map(game, line) == 1)
			return (1);
		line = get_next_line(fd);
	}
	return (0);
}