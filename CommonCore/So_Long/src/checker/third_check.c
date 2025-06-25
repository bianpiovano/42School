/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:31:12 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 19:04:06 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_has_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	write(2, "Error: Please, pick a map that includes an exit ♡\n", 53);
	return (0);
}

int	is_map_playable(char **map, t_point size, t_point begin)
{
	char	**copy;

	copy = copy_map(map, size);
	fill(copy, size, begin);
	if (has_inaccessible_collectibles(copy, size))
	{
		free_map(copy, size);
		return (0);
	}
	if (has_inaccessible_exit(copy, size))
	{
		free_map(copy, size);
		return (0);
	}
	free_map(copy, size);
	return (1);
}
