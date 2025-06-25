/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_for_play.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:58:25 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/23 18:46:07 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**copy_map(char **map, t_point size)
{
	char	**copy;
	int		i;
	int		j;

	copy = (char **)malloc(sizeof(char *) * (size.y + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < size.y)
	{
		copy[i] = (char *)malloc(sizeof(char) * (size.x + 1));
		if (!copy[i])
			return (free_copy(copy, i), NULL);
		j = -1;
		while (++j < size.x)
			copy[i][j] = map[i][j];
		copy[i][j] = '\0';
	}
	copy[i] = NULL;
	return (copy);
}

void	free_copy(char **copy, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(copy[j++]);
	free(copy);
}
