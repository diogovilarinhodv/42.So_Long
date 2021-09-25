#include "so_long.h"
#include <stdio.h>

int	key_hook(int key_hook, t_game *game)
{
	(void)game;

	if (key_hook == 0 || key_hook == 1 || key_hook == 2 || key_hook == 13)
        move(game, inc_x, inc_y);
	return (key_hook);
}

int main(int argc, char **argv)
{
	t_game game;

	game.counter = inic_counter();
	game.map = render_map();
	game.textures = render_textures();
	if(argc != 2)
		return (1);
	read_map_file(argv[argc - 1], &game);
	game.window = render_window(game);
	printing_textures(&game);
	mlx_hook(game.window.mlx_window, 2, 1L<<0, key_hook, &game);
	mlx_loop(game.window.mlx);
	free(game.map.matrix);
	return (0);
}