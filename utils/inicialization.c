#include "../src/so_long.h"

t_map	render_map(void)
{
	t_map	map;

	map.matrix = NULL;
	map.max_x = 0;
	map.max_y = 0;
	return (map);
}

t_counter	inic_counter(void)
{
	t_counter	count;

	count.player = 0;
	count.exit = 0;
	count.collect = 0;
	count.enemy = 0;
	count.wall = 0;
	count.floor = 0;
	return (count);
}

t_window	render_window(t_game g)
{
	t_window	win;
	int			width;
	int			height;

	width = (g.map.max_x - 1) * 100;
	height = g.map.max_y * 100;
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, width, height, "so_long");
	return (win);
}

char	*p(char ch)
{
	if (ch == 'P')
		return ("img/player.xpm");
	else if (ch == '1')
		return ("img/wall.xpm");
	else if (ch == '0')
		return ("img/floor.xpm");
	else if (ch == 'E')
		return ("img/exit.xpm");
	else if (ch == 'C')
		return ("img/collect.xpm");
	else if (ch == 'X')
		return ("img/enemy.xpm");
	return (NULL);
}

t_textures	render_textures(t_game g)
{
	t_textures	t;

	t.height = 0;
	t.width = 0;
	t.player = mlx_xpm_file_to_image(g.win.mlx, p('P'), &t.width, &t.height);
	t.wall = mlx_xpm_file_to_image(g.win.mlx, p('1'), &t.width, &t.height);
	t.floor = mlx_xpm_file_to_image(g.win.mlx, p('0'), &t.width, &t.height);
	t.exit = mlx_xpm_file_to_image(g.win.mlx, p('E'), &t.width, &t.height);
	t.collect = mlx_xpm_file_to_image(g.win.mlx, p('C'), &t.width, &t.height);
	t.enemy = mlx_xpm_file_to_image(g.win.mlx, p('X'), &t.width, &t.height);
	return (t);
}
