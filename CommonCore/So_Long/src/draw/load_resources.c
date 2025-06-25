/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:57:58 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 14:58:17 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	load_resources(t_game *game)
{
	game->tile = mlx_xpm_file_to_image(game->mlx, "textures/tiles/tile.xpm",
			&game->image_width, &game->image_height);
	game->counter = mlx_xpm_file_to_image(game->mlx,
			"textures/tiles/newcounter.xpm", &game->counter_width,
			&game->image_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/tiles/wall.xpm",
			&game->image_width, &game->image_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectibles/raindrop.xpm", &game->image_width,
			&game->image_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit/exit00.xpm",
			&game->image_width, &game->image_height);
	if (!game->tile || !game->wall || !game->exit || !game->collectible)
	{
		write(2, "Error loading sprites.\n", 23);
		return (1);
	}
	return (0);
}

int	load_player(t_game *game)
{
	game->player[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/hellokitty00.xpm", &game->image_width,
			&game->image_height);
	game->player[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/hellokitty01.xpm", &game->image_width,
			&game->image_height);
	game->player[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/hellokitty02.xpm", &game->image_width,
			&game->image_height);
	game->player[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/hellokitty03.xpm", &game->image_width,
			&game->image_height);
	if (!game->player[0] || !game->player[1] || !game->player[2]
		|| !game->player[3])
	{
		write(2, "Error loading player sprites.\n", 29);
		return (1);
	}
	return (0);
}
