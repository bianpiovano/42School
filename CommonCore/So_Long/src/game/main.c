/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:54:01 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/14 20:29:26 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int main()
{
    t_game game;

	int	window_width;
	int	window_height;

    window_width = 0;
    window_height = 0;

    game.mlx = mlx_init();

    // map
    game.map = read_map("/home/bianca/1-Proyectos/So_Long/maps/map00.ber");
    if (!game.map)
    {
        write(2, "Error loading map\n", 18);
        return (1);
    }
    // end
    if (get_map_dimensions("/home/bianca/1-Proyectos/So_Long/maps/map00.ber", &game.map_width, &game.map_height, &game) == -1)
    {
        write(2, "Error: Failed to get map dimensions\n", 35);
        return (1);
    }
    
    window_width = game.map_width * IMAGE_SIZE;
    window_height = game.map_height * IMAGE_SIZE;

    if (window_width <= 0 || window_height <= 0) 
    {
        write(2, "Error: Invalid window dimensions\n", 33);
        return 1;
    }

    game.window = mlx_new_window(game.mlx, window_width, window_height, "So Kitty");
    
    if (!game.mlx || !game.window)
    return (1);

    game.player_x = 1;
    game.player_y = 2;
    
    // images

    game.tile = mlx_xpm_file_to_image(game.mlx, "/home/bianca/1-Proyectos/So_Long/src/textures/tiles/tile.xpm", &game.image_width, &game.image_height);
    game.wall = mlx_xpm_file_to_image(game.mlx, "/home/bianca/1-Proyectos/So_Long/src/textures/tiles/wall.xpm", &game.image_width, &game.image_height);
    game.collectible = mlx_xpm_file_to_image(game.mlx, "/home/bianca/1-Proyectos/So_Long/src/textures/collectibles/raindrop1.xpm", &game.image_width, &game.image_height);
    if (!game.collectible)
{
    write(2, "Error loading collectible image\n", 32);
    return (1);
}
    // player
    
    game.player[0] = mlx_xpm_file_to_image(game.mlx, "/home/bianca/1-Proyectos/So_Long/src/textures/player/hellokitty00.xpm", &game.image_width, &game.image_height);
    game.player[1] = mlx_xpm_file_to_image(game.mlx, "/home/bianca/1-Proyectos/So_Long/src/textures/player/hellokitty01.xpm", &game.image_width, &game.image_height);
    game.player[2] = mlx_xpm_file_to_image(game.mlx, "/home/bianca/1-Proyectos/So_Long/src/textures/player/hellokitty02.xpm", &game.image_width, &game.image_height);
    game.player[3] = mlx_xpm_file_to_image(game.mlx, "/home/bianca/1-Proyectos/So_Long/src/textures/player/hellokitty03.xpm", &game.image_width, &game.image_height);

    if (!game.tile || !game.wall || !game.player[0] || !game.player[1] || !game.player[2] || !game.player[3])
    {
        write(2, "Error loading sprites\n", 22);
        return (1);
    }

    draw_tiles(&game);
    draw_walls(&game);
    mlx_put_image_to_window(game.mlx, game.window, game.player[0], game.player_x * IMAGE_SIZE, game.player_y * IMAGE_SIZE);

    mlx_key_hook(game.window, key_press, &game);

    mlx_hook(game.window, 17, 0, (void *)close_window, NULL);

    mlx_loop(game.mlx);

    return (0);
}