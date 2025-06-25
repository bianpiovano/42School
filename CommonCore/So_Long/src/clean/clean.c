/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:28:21 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/23 17:36:00 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	clean_util(t_game *game)
{
	if (game->tile)
		mlx_destroy_image(game->mlx, game->tile);
	if (game->counter)
		mlx_destroy_image(game->mlx, game->counter);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}

void	cleanup_game(t_game *game)
{
	int	i;

	if (game->mlx)
	{
		i = 0;
		while (i < 4)
		{
			if (game->player[i])
				mlx_destroy_image(game->mlx, game->player[i]);
			i++;
		}
	}
	clean_util(game);
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}
