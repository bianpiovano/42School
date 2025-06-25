/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:29:19 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/23 18:49:14 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	draw_tiles(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->tile, x
					* IMAGE_SIZE, y * IMAGE_SIZE);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->wall, x
					* IMAGE_SIZE, y * IMAGE_SIZE);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->counter,
		(game->map_width - 2) * IMAGE_SIZE, (game->map_height - 1)
		* IMAGE_SIZE);
}

void	draw_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->collectible, x * IMAGE_SIZE, y * IMAGE_SIZE);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, x
					* IMAGE_SIZE, y * IMAGE_SIZE);
			x++;
		}
		y++;
	}
}

void	draw_scene(t_game *game)
{
	draw_tiles(game);
	draw_walls(game);
	draw_exit(game);
	draw_collectibles(game);
	count_collectibles(game);
	find_player_position(game);
	mlx_put_image_to_window(game->mlx, game->window, game->player[0],
		game->player_x * IMAGE_SIZE, game->player_y * IMAGE_SIZE);
}
