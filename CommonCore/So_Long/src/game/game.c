/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:54:01 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 19:11:00 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	init_window(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->map_width * IMAGE_SIZE;
	window_height = game->map_height * IMAGE_SIZE;
	if (window_width <= 0 || window_height <= 0)
	{
		write(2, "Error: Invalid window dimensions :(\n", 37);
		return (1);
	}
	game->window = mlx_new_window(game->mlx, window_width, window_height,
			"So Kitty");
	if (!game->window)
		return (1);
	return (0);
}

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
}

int	init_game(t_game *game, int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Correct usage: ./so_long <maps/map.ber>\n", 40);
		return (1);
	}
	game->mlx = mlx_init();
	game->map = read_map(argv[1]);
	if (!game->map)
	{
		write(2, "Error loading map.\n", 19);
		cleanup_game(game);
		return (1);
	}
	if (calculate_map_dimensions(argv[1], &game->map_width,
			&game->map_height) == -1)
	{
		write(2, "Error: Failed to get map dimensions :(\n", 40);
		cleanup_game(game);
		return (1);
	}
	game->image_height = IMAGE_SIZE;
	game->image_width = IMAGE_SIZE;
	game->counter_width = 2 * IMAGE_SIZE;
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, update_display, game);
	mlx_hook(game->window, 17, 0, (void *)close_window, game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!is_ber_map(argv[1]))
		return (write(2, "Error: The map must be in a .ber file :(\n", 42), 1);
	memset(&game, 0, sizeof(t_game));
	if (init_game(&game, argc, argv))
		return (1);
	if (!validating_map(&game, game.map))
		return (1);
	game.player_x = 1;
	game.player_y = 2;
	game.move_count = 0;
	game.frame_count = 0;
	game.pressed_key = 0;
	if (init_window(&game))
		return (1);
	if (load_resources(&game))
		return (1);
	if (load_player(&game))
		return (1);
	draw_scene(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
