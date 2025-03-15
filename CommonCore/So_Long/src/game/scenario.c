/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:28:30 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/15 12:03:48 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h" 

// collectibles
void spawn_collectibles(t_game *game)
{
    int x, y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->collectible, x * IMAGE_SIZE, y * IMAGE_SIZE);
            x++;
        }
        y++;
    }
}
