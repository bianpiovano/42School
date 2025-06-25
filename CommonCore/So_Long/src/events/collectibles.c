/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:09:26 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 18:07:05 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	check_victory(t_game *game)
{
	int	i;
	int	j;

	if (game->collected_collectibles == game->total_collectibles)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"textures/exit/exit03.xpm",
				&game->image_width, &game->image_height);
		j = -1;
		while (++j < game->map_height)
		{
			i = -1;
			while (++i < game->map_width)
			{
				if (game->map[j][i] == 'E')
					mlx_put_image_to_window(game->mlx, game->window, game->exit,
						game->image_width * i, game->image_height * j);
			}
		}
	}
}

void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->total_collectibles = 0;
	game->collected_collectibles = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->total_collectibles++;
			x++;
		}
		y++;
	}
}
