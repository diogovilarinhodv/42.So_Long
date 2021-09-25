#include "so_long.h"
#include <stdio.h>

int	key_hook(int key_hook, t_game *game)
{
	(void)game;

	if (key_hook == 0)
	{
		if (game->map.matrix[game->player.y][game->player.x - 1] != '1')
		{
			game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.floor, &game->textures.img_width, &game->textures.img_height);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100), (game->player.y * 100));
			game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.player, &game->textures.img_width, &game->textures.img_height);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100) - 100, (game->player.y * 100));
			game->player.x -= 1;
		}
		printf("A pressed!\n");
	}
	else if (key_hook == 1)
	{
		if (game->map.matrix[game->player.y + 1][game->player.x] != '1')
		{
			game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.floor, &game->textures.img_width, &game->textures.img_height);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100), (game->player.y * 100));
			game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.player, &game->textures.img_width, &game->textures.img_height);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100), (game->player.y * 100) + 100);
			game->player.y += 1;
		}
		printf("S pressed!\n");
	}
		
	else if (key_hook == 2)
	{
		if (game->map.matrix[game->player.y][game->player.x + 1] != '1')
		{
			game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.floor, &game->textures.img_width, &game->textures.img_height);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100), (game->player.y * 100));
			game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.player, &game->textures.img_width, &game->textures.img_height);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100) + 100, (game->player.y * 100));
			game->player.x += 1;
		}
		printf("D pressed!\n");
	}
	else if (key_hook == 13)
	{
		if (game->map.matrix[game->player.y - 1][game->player.x] != '1')
		{
			game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.floor, &game->textures.img_width, &game->textures.img_height);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100), (game->player.y * 100));
			game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.player, &game->textures.img_width, &game->textures.img_height);
			mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100), (game->player.y * 100) - 100);
			game->player.y -= 1;
		}
		printf("W pressed!\n");
	}

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