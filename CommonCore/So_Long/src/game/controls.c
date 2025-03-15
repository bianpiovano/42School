/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:31:43 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/13 18:20:38 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void draw_player(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->window, game->player[game->direction], game->player_x * IMAGE_SIZE, game->player_y * IMAGE_SIZE);
}
int key_press(int keycode, t_game *game)
{
    int new_x = game->player_x;
    int new_y = game->player_y;
    int old_x = game->player_x;
    int old_y = game->player_y;

    if (keycode == 65364 || keycode == 115) // down
    {
        new_y += 1;
        game->direction = 0;
    }
    else if (keycode == 65362 || keycode == 119) // up
    {
        new_y -= 1;
        game->direction = 1;
    }
    else if (keycode == 65363 || keycode == 100) // right
    {
        new_x += 1;
        game->direction = 2;
    }
    else if (keycode == 65361 || keycode == 97) // left
    {
        new_x -= 1;
        game->direction = 3;
    }
    else if (keycode == 65307) // escape
    {
        exit(0);
    }

    if (game->map[new_y][new_x] != '1') 
    {
        game->player_x = new_x;
        game->player_y = new_y;
    }

    mlx_put_image_to_window(game->mlx, game->window, game->tile, old_x * IMAGE_SIZE, old_y * IMAGE_SIZE);

    draw_player(game);
    return (0);
}
