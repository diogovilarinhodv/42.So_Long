#include "so_long.h"

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
    mlx_loop(game.window.mlx);
    return (0);
}