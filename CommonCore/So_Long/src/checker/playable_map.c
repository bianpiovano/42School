/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:25:11 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 12:51:08 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill(char **tab, t_point size, t_point current)
{
	if (current.y < 0 || current.x < 0 || current.y >= size.y
		|| current.x >= size.x)
		return ;
	if (tab[current.y][current.x] != '0' && tab[current.y][current.x] != 'C'
		&& tab[current.y][current.x] != 'E' && tab[current.y][current.x] != 'P')
		return ;
	if (tab[current.y][current.x] != 'E')
		tab[current.y][current.x] = 'F';
	fill(tab, size, (t_point){current.x - 1, current.y});
	fill(tab, size, (t_point){current.x + 1, current.y});
	fill(tab, size, (t_point){current.x, current.y - 1});
	fill(tab, size, (t_point){current.x, current.y + 1});
}

void	free_map(char **map, t_point size)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < size.y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	is_exit_accessible(char **map, t_point size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (map[i][j] == 'E')
			{
				if ((i > 0 && map[i - 1][j] == 'F') || (i < size.y - 1 && map[i
						+ 1][j] == 'F') || (j > 0 && map[i][j - 1] == 'F')
					|| (j < size.x - 1 && map[i][j + 1] == 'F'))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	has_inaccessible_collectibles(char **copy, t_point size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (copy[i][j] == 'C')
			{
				write(1, "Error: There is an inaccessible collectible. ", 46);
				write(1, "Please try another map ♡\n", 28);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	has_inaccessible_exit(char **copy, t_point size)
{
	if (!is_exit_accessible(copy, size))
	{
		write(1, "Error: The exit is inaccessible. Please try another map ♡\n",
			73);
		return (1);
	}
	return (0);
}
