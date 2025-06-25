/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:41:55 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 19:18:11 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_ber_map(const char *filename)
{
	size_t	len;

	len = strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strcmp(filename + len - 4, ".ber") == 0);
}

int	map_is_empty(char **map)
{
	if (!map || !map[0])
	{
		write(2, "Error: Map is empty or not loaded :(\n", 38);
		return (0);
	}
	return (1);
}

int	map_is_rectangular(char **map)
{
	int	len;
	int	i;
	int	curr_len;

	len = ft_strlen(map[0]);
	if (map[0][len - 1] == '\n')
		len--;
	i = 0;
	while (map[++i])
	{
		curr_len = ft_strlen(map[i]);
		if (map[i][curr_len - 1] == '\n')
			curr_len--;
		if (curr_len != len)
		{
			write(1, "Error: Please try with a rectangular map ♡\n", 46);
			return (0);
		}
	}
	return (1);
}

int	is_allowed_char(char c)
{
	return (c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P');
}

int	map_has_only_allowed_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
			{
				j++;
				continue ;
			}
			if (!is_allowed_char(map[i][j]))
				return (write(2,
						"Error: Please check there is valid char in map ♡\n",
						58), 0);
			j++;
		}
		i++;
	}
	return (1);
}
