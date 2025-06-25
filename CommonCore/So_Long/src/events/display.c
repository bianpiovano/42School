/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:12:21 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 17:12:13 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	update_moves_display(t_game *game)
{
	char	buf[12];
	int		len;
	char	buf2[12];

	len = ft_sprintf(buf, "Moves: %d\n", game->move_count);
	ft_sprintf(buf2, "Moves: %d", game->move_count);
	if (game->move_count < 1000)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->counter,
			(game->map_width - 2) * IMAGE_SIZE, (game->map_height - 1)
			* IMAGE_SIZE);
		mlx_string_put(game->mlx, game->window, (game->map_width - 2)
			* IMAGE_SIZE + 10, (game->map_height - 1) * IMAGE_SIZE + 19,
			0x761919, buf2);
	}
	write(1, buf, len);
}

int	update_display(t_game *game)
{
	if (!should_update(game))
		return (0);
	handle_player_movement(game);
	return (0);
}

int	should_update(t_game *game)
{
	if (game->pressed_key == 0)
		return (0);
	game->frame_count++;
	if (game->frame_count < 8000)
		return (0);
	game->frame_count = 0;
	return (1);
}
