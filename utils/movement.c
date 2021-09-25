#include "so_long.h"

void	move(t_game *game, int inc_x, int inc_y)
{
	char ch;

	ch = game->map.matrix[game->player.y + inc_y][game->player.x + inc_x];
	if (ch != '1' || (ch == 'E' && game->counter.collector == 0)) 
	{
		game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.floor, &game->textures.img_width, &game->textures.img_height);
		mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100), (game->player.y * 100));
		game->image.texture = mlx_xpm_file_to_image(game->window.mlx, game->textures.player, &game->textures.img_width, &game->textures.img_height);
		mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, (game->player.x * 100) + (inc_x * 100), (game->player.y * 100)  + (inc_y * 100));
		if (inc_x != 0)
			game->player.x += inc_x;
		else if (inc_y != 0)
			game->player.y += inc_y;
		if (ch == 'C')
			game->counter.collector--;
		game->player.moves++;
	}
}
