/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:30:40 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 19:06:49 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	validating_map(t_game *game, char **map)
{
	t_point	size;
	t_point	begin;

	if (!map)
	{
		write(2, "Error: Map pointer is NULL :(\n", 31);
		return (close_window(game), 0);
	}
	size = map_size(map);
	begin = find_player_start_position(map);
	if (map_is_rectangular(map) == 0 || map_has_only_allowed_chars(map) == 0
		|| map_has_single_exit(map) == 0 || map_has_single_player(map) == 0
		|| map_has_collectibles(map) == 0 || map_has_exit(map) == 0
		|| is_map_closed(map) == 0
		|| can_reach_all_collectibles_without_exit(map, size, begin) == 0)
	{
		close_window(game);
		return (0);
	}
	if (is_map_playable(map, size, begin) == 0)
		return (close_window(game), 0);
	return (1);
}
