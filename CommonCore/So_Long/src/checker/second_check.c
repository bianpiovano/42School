/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:29:06 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/23 18:44:35 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	map_has_single_exit(char **map)
{
	int	i;
	int	j;
	int	exit_count;

	exit_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count > 1)
	{
		write(2, "Error: Please, pick a map that includes only one exit ♡\n",
			59);
		return (0);
	}
	return (1);
}

int	map_has_single_player(char **map)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		write(2,
			"Error: Please check you are using a map with a single player ♡\n",
			66);
		return (0);
	}
	return (1);
}

int	map_has_collectibles(char **map)
{
	int	i;
	int	j;
	int	collectibles_count;

	collectibles_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectibles_count++;
			j++;
		}
		i++;
	}
	if (collectibles_count == 0)
	{
		write(2, "Error: Please, pick a map that includes collectibles ♡\n",
			58);
		return (0);
	}
	return (1);
}
