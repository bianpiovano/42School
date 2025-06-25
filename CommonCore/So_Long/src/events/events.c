/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:28:30 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/23 17:36:25 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		cleanup_game(game);
		exit(0);
	}
	game->pressed_key = keycode;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (game->pressed_key == keycode)
		game->pressed_key = 0;
	return (0);
}
