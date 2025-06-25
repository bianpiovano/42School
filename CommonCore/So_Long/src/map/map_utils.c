/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:16:34 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/21 23:29:55 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_point	map_size(char **map)
{
	t_point	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size.x = 0;
	size.y = 0;
	while (map[0][j] && map[0][j] != '\n')
		j++;
	size.x = j;
	while (map[i])
		i++;
	size.y = i;
	return (size);
}

t_point	find_player_start_position(char **map)
{
	t_point	pos;
	int		i;
	int		j;

	i = 0;
	pos.x = -1;
	pos.y = -1;
	if (!map)
		return (pos);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}
