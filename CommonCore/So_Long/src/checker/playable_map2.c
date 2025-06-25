/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:40:06 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 16:56:48 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_no_exit(char **map, int **visited, t_point size, t_point current)
{
	if (current.y < 0 || current.x < 0 || current.y >= size.y
		|| current.x >= size.x)
		return ;
	if (visited[current.y][current.x])
		return ;
	if (map[current.y][current.x] == '1' || map[current.y][current.x] == 'E')
		return ;
	visited[current.y][current.x] = 1;
	fill_no_exit(map, visited, size, (t_point){current.x + 1, current.y});
	fill_no_exit(map, visited, size, (t_point){current.x - 1, current.y});
	fill_no_exit(map, visited, size, (t_point){current.x, current.y + 1});
	fill_no_exit(map, visited, size, (t_point){current.x, current.y - 1});
}

int	all_collectibles_reachable(char **map, int **visited, t_point size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (map[i][j] == 'C' && !visited[i][j])
			{
				write(2, "Error: There is an unreachable collectible. \n", 46);
				write(2, "Try another map ♡\n", 21);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	can_reach_all_collectibles_without_exit(char **map, t_point size,
		t_point start)
{
	int	**visited;
	int	i;
	int	res;

	visited = malloc(size.y * sizeof(int *));
	if (!visited)
		return (0);
	i = 0;
	while (i < size.y)
		visited[i++] = calloc(size.x, sizeof(int));
	fill_no_exit(map, visited, size, start);
	res = all_collectibles_reachable(map, visited, size);
	i = 0;
	while (i < size.y)
		free(visited[i++]);
	free(visited);
	return (res);
}
