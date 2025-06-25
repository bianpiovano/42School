/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:06:11 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 15:05:19 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	compute_new_position(t_game *game, int *new_x, int *new_y)
{
	*new_x = game->player_x;
	*new_y = game->player_y;
	if (game->pressed_key == 65364 || game->pressed_key == 115)
	{
		(*new_y)++;
		game->direction = 0;
	}
	else if (game->pressed_key == 65362 || game->pressed_key == 119)
	{
		(*new_y)--;
		game->direction = 1;
	}
	else if (game->pressed_key == 65363 || game->pressed_key == 100)
	{
		(*new_x)++;
		game->direction = 2;
	}
	else if (game->pressed_key == 65361 || game->pressed_key == 97)
	{
		(*new_x)--;
		game->direction = 3;
	}
}

void	handle_player_movement(t_game *game)
{
	int	new_x;
	int	new_y;
	int	old_x;
	int	old_y;

	old_y = game->player_y;
	old_x = game->player_x;
	old_y = game->player_y;
	compute_new_position(game, &new_x, &new_y);
	draw_player(game);
	if (!process_tile(game, new_x, new_y))
		return ;
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	update_moves_display(game);
	mlx_put_image_to_window(game->mlx, game->window, game->tile, old_x
		* IMAGE_SIZE, old_y * IMAGE_SIZE);
	if (game->map[old_y][old_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, old_x
			* IMAGE_SIZE, old_y * IMAGE_SIZE);
	draw_player(game);
}

int	process_tile(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected_collectibles++;
		game->map[new_y][new_x] = '0';
		check_victory(game);
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collected_collectibles == game->total_collectibles)
		{
			write(1, "¡VICTORY!\n", 11);
			cleanup_game(game);
			exit(0);
		}
		else
		{
			write(1, "You need to collect all the raindrops 💧\n", 44);
			return (0);
		}
	}
	return (1);
}
