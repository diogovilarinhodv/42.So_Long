#include "../src/so_long.h"

t_map render_map()
{
	t_map map;

	map.matrix = NULL;
	map.max_x = 0;
	map.max_y = 0;
	return (map);
}

t_counter inic_counter()
{
	t_counter counter;

	counter.player = 0;
	counter.exit = 0;
	counter.collector = 0;
	counter.enemy = 0;
	counter.wall = 0;
	counter.floor = 0;
	return (counter);
}

t_window render_window(t_game game)
{
	t_window window;

	window.mlx = mlx_init();
	window.mlx_window = mlx_new_window(window.mlx, ((game.map.max_x - 1) * 100), (game.map.max_y * 100), "so_long");
	return (window);
}

t_textures render_textures()
{
	t_textures textures;

	// vscode with "../img/", bash with "img/" 
	textures.player = "img/player.xpm";
	textures.wall = "img/wall.xpm";
	textures.floor = "img/floor.xpm";
	textures.exit = "img/exit.xpm";
	textures.colectables = "img/collector.xpm";
	textures.enemy = "/img/enemy.xpm";
	textures.img_height = 0;
	textures.img_width = 0;
	return (textures);
}

t_image render_image()
{
	t_image image;
	
	image.pos_x = 0;
	image.pos_y = 0;
	return (image);
}
