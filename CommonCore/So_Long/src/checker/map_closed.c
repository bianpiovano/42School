/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:37:14 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/23 18:46:29 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_row_closed(char *row, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		if (row[j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	are_sides_closed(char **map, int width)
{
	int	i;

	i = 1;
	while (map[i + 1])
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_closed(char **map)
{
	int	width;
	int	i;
	int	last;

	width = 0;
	i = 0;
	while (map[0][width] && map[0][width] != '\n')
		width++;
	last = 0;
	while (map[last])
		last++;
	last--;
	if (!is_row_closed(map[0], width) || !is_row_closed(map[last], width))
	{
		write(2, "Error: The map should be closed on the top/bottom ♡\n", 55);
		return (0);
	}
	if (!are_sides_closed(map, width))
	{
		write(2, "Error: The map should be closed on the sides ♡\n", 50);
		return (0);
	}
	return (1);
}
