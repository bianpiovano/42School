/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:41:35 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/14 19:44:39 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    exit(0);
}

// obtener dimesiones del mapa para crear ventana
int get_map_dimensions(const char *filename, int *width, int *height, t_game *game) 
{
    int fd = open(filename, O_RDONLY);

    
    if (fd == -1) {
        write(2, "Error opening file\n", 19);
        return -1;  // Error al abrir el archivo
    }

    char buffer[1024];
    int map_width = 0;
    int map_height = 0;
    ssize_t bytes_read;

    // Leemos el archivo línea por línea
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';  // Terminamos la cadena leída

        char *line = strtok(buffer, "\n");

        while (line != NULL) {
            if (map_width == 0) {
                map_width = strlen(line);  // El ancho es la longitud de la primera línea
            }
            map_height++;  // Incrementamos la altura por cada línea
            line = strtok(NULL, "\n");
        }
    }

    close(fd);

    // Si no se pudo calcular el mapa, devolvemos error
    if (map_width == 0 || map_height == 0) 
    {
        write(2, "Error calculating map dimensions\n", 31);
        return -1;
    }

    // Asignamos las dimensiones a los parámetros pasados
    *width = map_width;
    *height = map_height;

    // Guardamos las dimensiones en la estructura game
    game->map_width = map_width;
    game->map_height = map_height;

    return 0;  // Todo ha ido bien
}


