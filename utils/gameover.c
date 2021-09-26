#include "../src/so_long.h"

void	game_over(t_game *g)
{
	mlx_destroy_image(g->win.mlx, g->textures.wall);
	mlx_destroy_image(g->win.mlx, g->textures.floor);
	mlx_destroy_image(g->win.mlx, g->textures.player);
	mlx_destroy_image(g->win.mlx, g->textures.collect);
	mlx_destroy_image(g->win.mlx, g->textures.exit);
	mlx_destroy_image(g->win.mlx, g->textures.enemy);
	mlx_destroy_window(g->win.mlx, g->win.mlx_win);
	free(g->map.matrix);
}
