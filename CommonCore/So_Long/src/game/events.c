/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:28:30 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/24 16:12:31 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h" 

void count_collectibles(t_game *game)
{
    int x, y;

    game->total_collectibles = 0;
    game->collected_collectibles = 0;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'C')
                game->total_collectibles++;
            x++;
        }
        y++;
    }
}

void check_victory(t_game *game)
{
    if (game->collected_collectibles == game->total_collectibles)
    {
        game->exit = mlx_xpm_file_to_image(game->mlx, "/home/bianca/1-Proyectos/So_Long/src/textures/exit/exit03.xpm", &game->image_width, &game->image_height);
    }
}

int key_press(int keycode, t_game *game)
{
    if (keycode == 65307) // Escape
        exit(0);
    game->pressed_key = keycode; // Guardamos la tecla presionada
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (game->pressed_key == keycode)
        game->pressed_key = 0;
    return (0);
}

void compute_new_position(t_game *game, int *new_x, int *new_y)
{
    *new_x = game->player_x;
    *new_y = game->player_y;
    if (game->pressed_key == 65364 || game->pressed_key == 115) // Down (↓ o 's')
    {
        (*new_y)++;
        game->direction = 0;
    }
    else if (game->pressed_key == 65362 || game->pressed_key == 119) // Up (↑ o 'w')
    {
        (*new_y)--;
        game->direction = 1;
    }
    else if (game->pressed_key == 65363 || game->pressed_key == 100) // Right (→ o 'd')
    {
        (*new_x)++;
        game->direction = 2;
    }
    else if (game->pressed_key == 65361 || game->pressed_key == 97) // Left (← o 'a')
    {
        (*new_x)--;
        game->direction = 3;
    }
}

int process_tile(t_game *game, int new_x, int new_y)
{
    // No moverse contra paredes
    if (game->map[new_y][new_x] == '1')
        return (0);

    // Si es un coleccionable, recogerlo
    if (game->map[new_y][new_x] == 'C')
    {
        game->collected_collectibles++;
        game->map[new_y][new_x] = '0';
    }

    // Verificar la salida
    if (game->map[new_y][new_x] == 'E')
    {
        if (game->collected_collectibles == game->total_collectibles)
        {
            write(1, "¡VICTORY!\n", 11);
            exit(0);
        }
        else
        {
            write(1, "You need to collect all the raindrops.\n", 38);
            return (0);
        }
    }
    return (1);
}

void update_moves_display(t_game *game)
{
    char buf[12];
    int len = sprintf(buf, "Moves: %d\n", game->move_count);
    char buf2[12];
    sprintf(buf2, "Moves: %d", game->move_count);

    if (game->move_count < 1000)
    {
        mlx_put_image_to_window(game->mlx, game->window, game->counter, 
            (game->map_width - 2) * IMAGE_SIZE, (game->map_height - 1) * IMAGE_SIZE);
        mlx_string_put(game->mlx, game->window, 
            (game->map_width - 2) * IMAGE_SIZE + 10, (game->map_height - 1) * IMAGE_SIZE + 19, 
            0x761919, buf2);
    }
    write(1, buf, len);
}

int update_display(t_game *game)
{
    if (game->pressed_key == 0)
        return (0);

    game->frame_count++;
    if (game->frame_count < 2500) // Ajusta este valor para cambiar la velocidad
        return (0);
    game->frame_count = 0;

    int new_x;
    int new_y;
    int old_x = game->player_x;
    int old_y = game->player_y;

    // Calcular la nueva posición
    compute_new_position(game, &new_x, &new_y);
    
    // Dibuja al jugador (puedes dejarlo aquí o integrarlo en otra función)
    draw_player(game);

    // Procesar colisión y eventos
    if (!process_tile(game, new_x, new_y))
        return (0);

    // Actualizar la posición del jugador y el contador de movimientos
    game->player_x = new_x;
    game->player_y = new_y;
    game->move_count++;
    update_moves_display(game);

    // Redibujar el tile de la posición antigua
    mlx_put_image_to_window(game->mlx, game->window, game->tile, old_x * IMAGE_SIZE, old_y * IMAGE_SIZE);
    if (game->map[old_y][old_x] == 'E')
        mlx_put_image_to_window(game->mlx, game->window, game->exit, old_x * IMAGE_SIZE, old_y * IMAGE_SIZE);

    // Dibujar al jugador en la nueva posición
    draw_player(game);

    return (0);
}