/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:16:34 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/13 18:20:40 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char **read_map(char *filename)
{
    int fd;
    char *line;
    char **map;
    char **new_map;
    int i;
    int j;
    int size;

    i = 0;
    j = 0;
    size = 10;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Invalid file\n", 13);
        return (NULL);
    }
    map = malloc(sizeof(char *) * (size + 1));
    if (!map)
    {
        write(2, "Error allocating memory for map\n", 31);
        close(fd);
        return (NULL);
    }
    line = get_next_line(fd);
    while (line)
    {
        map[i] = line;
        i++;

        if (i >= size)
        {
            new_map = malloc(sizeof(char *) * (size * 2 + 1));
            if (!new_map)
            {
                write(2, "Error allocating memory for new map\n", 36);
                close(fd);
                return (NULL);
            }
            while (j < i)
            {
                new_map[j] = map[j];
                j++;
            }
            free(map);
            map = new_map;
            size *= 2;
        }
        line = get_next_line(fd);
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

void free_map_memory(t_game *game)
{
    int i = 0;

    if (!game->map) // Evita errores si el mapa ya es NULL
        return;

    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    game->map = NULL; // Evita doble free si la función se llama dos veces
}
