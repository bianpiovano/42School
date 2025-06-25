/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:49:23 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/23 18:49:40 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	write(2, "Error: No 'P' was found on the map.\n", 36);
	exit(1);
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->player[game->direction], game->player_x * IMAGE_SIZE,
		game->player_y * IMAGE_SIZE);
}
