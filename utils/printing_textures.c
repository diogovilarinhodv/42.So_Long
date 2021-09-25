#include "../src/so_long.h"

static char*	get_texture(t_game *game,char ch)
{
	if (ch == 'P')
	{
		game->counter.player++;
		return (game->textures.player);
	}
	else if (ch == 'E')
	{
		game->counter.exit++;
		return (game->textures.exit);
	}
	else if (ch == 'C')
	{
		game->counter.collector++;
		return (game->textures.colectables);
	}
	else if (ch == '1')
		return (game->textures.wall);
	else if (ch == '0')
		return (game->textures.floor);
	else if (ch == 'X')
		return (game->textures.enemy);
	else
		return (NULL);
}

static int		count_check(t_game *game)
{
	if (game->counter.player != 1 || game->counter.exit != 1)
		return (1);
	return (0);
}

static void		set_textures(t_game *game, int inc_x, int inc_y, char *texture_to_print)
{
	game->image.pos_x = (inc_x * 100);
	game->image.pos_y = (inc_y * 100);
	game->image.texture = mlx_xpm_file_to_image(game->window.mlx, texture_to_print, &game->textures.img_width, &game->textures.img_height);
	mlx_put_image_to_window(game->window.mlx, game->window.mlx_window, game->image.texture, game->image.pos_x, game->image.pos_y);
}

int				printing_textures(t_game *game)
{
	int		inc_x;
	int		inc_y;
	char	*texture_to_print;

	inc_x = 0;
	inc_y = 0;
	while(inc_y < game->map.max_y)
	{
		while(inc_x < game->map.max_x - 1)
		{
			texture_to_print = get_texture(game, game->map.matrix[inc_y][inc_x]);
			set_textures(game, inc_x, inc_y, texture_to_print);
			inc_x++;
		}
		inc_x = 0;
		inc_y++;
	}
	if (count_check(game))
		return (1);
	return (0);
}

