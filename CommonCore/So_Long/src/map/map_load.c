/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:26:14 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 14:20:12 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**load_map_from_fd(int fd)
{
	char	**map;
	int		size;

	size = 10;
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
	{
		write(2, "Error: Failed allocating memory for map :(\n", 44);
		return (NULL);
	}
	map = fill_map(fd, map, &size);
	return (map);
}

char	**fill_map(int fd, char **map, int *size)
{
	char	*line;
	int		i;
	size_t	len;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i++] = line;
		if (i >= *size)
		{
			map = expand_map(map, size, i);
			if (!map)
				return (NULL);
		}
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**expand_map(char **map, int *size, int i)
{
	char	**new_map;
	int		j;

	new_map = malloc(sizeof(char *) * ((*size) * 2 + 1));
	if (!new_map)
	{
		write(2, "Error: Failed allocating memory for new map :(\n", 48);
		return (NULL);
	}
	j = -1;
	while (++j < i)
		new_map[j] = map[j];
	free(map);
	*size *= 2;
	return (new_map);
}

void	free_map_memory(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}
