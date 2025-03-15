/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:29:19 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/13 17:48:40 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void draw_tiles(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;

    while (game->map[y]) {
        while (game->map[y][x]) {
            if (game->map[y][x] == '0')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->tile, x * IMAGE_SIZE, y * IMAGE_SIZE);
            }
            x++;
        }
        x = 0;
        y++;
    }
}

void draw_walls(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y]) 
    {
        x = 0;
        while (game->map[y][x]) 
        {
            if (game->map[y][x] == '1')
            {
                mlx_put_image_to_window(game->mlx, game->window, game->wall, x * IMAGE_SIZE, y * IMAGE_SIZE);
            }
            x++;
        }
        y++;
    }
}