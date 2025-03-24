/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:54:01 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/24 16:14:48 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int init_window(t_game *game)
{
    int window_width = game->map_width * IMAGE_SIZE;
    int window_height = game->map_height * IMAGE_SIZE;

    if (window_width <= 0 || window_height <= 0)
    {
        write(2, "Error: Invalid window dimensions\n", 33);
        return (1);
    }
    game->window = mlx_new_window(game->mlx, window_width, window_height, "So Kitty");
    if (!game->window)
        return (1);
    return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

// Función para inicializar el juego (mapa, MLX, etc.)
int init_game(t_game *game, int argc, char *argv[])
{
    if (argc != 2)
    {
        write(2, "Correct usage: ./so_long <maps/map.ber>\n", 39);
        return (1);
    }
    game->mlx = mlx_init();
    game->map = read_map(argv[1]);
    if (!game->map)
    {
        write(2, "Error loading map\n", 18);
        return (1);
    }
    if (get_map_dimensions(argv[1], &game->map_width, &game->map_height, game) == -1)
    {
        write(2, "Error: Failed to get map dimensions\n", 35);
        return (1);
    }
    return (0);
}

void setup_hooks(t_game *game)
{
    mlx_hook(game->window, 2, 1L << 0, key_press, game);
    mlx_hook(game->window, 3, 1L << 1, key_release, game);
    mlx_loop_hook(game->mlx, update_display, game);
    mlx_hook(game->window, 17, 0, (void *)close_window, NULL);
}

int main(int argc, char *argv[])
{
    t_game game;

    game.player_x = 1;
    game.player_y = 2;
    game.move_count = 0;
    game.frame_count = 0;
    game.pressed_key = 0;

    if (init_game(&game, argc, argv))
        return (1);
    if (init_window(&game))
        return (1);
    if (load_resources(&game))
        return (1);

    draw_scene(&game);
    setup_hooks(&game);
    mlx_loop(game.mlx);
    return (0);
}
