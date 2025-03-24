/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <	bpiovano@student.42luxembour    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:29:19 by bpiovano          #+#    #+#             */
/*   Updated: 2025/03/24 16:22:49 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	find_player_position(t_game *game)
{
	int x, y;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	write(2, "Error: No se encontró 'P' en el mapa\n", 36);
	exit(1);
}

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->player[game->direction], game->player_x * IMAGE_SIZE,
		game->player_y * IMAGE_SIZE);
}

void	draw_tiles(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->tile, x
					* IMAGE_SIZE, y * IMAGE_SIZE);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->window, game->wall, x
					* IMAGE_SIZE, y * IMAGE_SIZE);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->counter,
		(game->map_width - 2) * IMAGE_SIZE, (game->map_height - 1)
		* IMAGE_SIZE);
}

void	draw_collectibles(t_game *game)
{
	int x, y;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->collectible, x * IMAGE_SIZE, y * IMAGE_SIZE);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_game *game)
{
	int x, y;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit, x
					* IMAGE_SIZE, y * IMAGE_SIZE);
			x++;
		}
		y++;
	}
}

void	draw_scene(t_game *game)
{
	draw_tiles(game);
	draw_walls(game);
	draw_exit(game);
	draw_collectibles(game);
	count_collectibles(game);
	find_player_position(game);
	mlx_put_image_to_window(game->mlx, game->window, game->player[0],
		game->player_x * IMAGE_SIZE, game->player_y * IMAGE_SIZE);
}

int	load_resources(t_game *game)
{
	game->tile = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/tiles/tile.xpm",
			&game->image_width, &game->image_height);
	game->counter = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/tiles/newcounter.xpm",
			&game->counter_width, &game->image_height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/tiles/wall.xpm",
			&game->image_width, &game->image_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/collectibles/raindrop.xpm",
			&game->image_width, &game->image_height);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/exit/exit00.xpm",
			&game->image_width, &game->image_height);
	game->player[0] = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/player/hellokitty00.xpm",
			&game->image_width, &game->image_height);
	game->player[1] = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/player/hellokitty01.xpm",
			&game->image_width, &game->image_height);
	game->player[2] = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/player/hellokitty02.xpm",
			&game->image_width, &game->image_height);
	game->player[3] = mlx_xpm_file_to_image(game->mlx,
			"/home/bianca/1Nueva Version So Long/So_Long/assets/player/hellokitty03.xpm",
			&game->image_width, &game->image_height);

	if (!game->tile || !game->wall || !game->player[0] || !game->player[1]
		|| !game->player[2] || !game->player[3])
	{
		write(2, "Error loading sprites\n", 22);
		return (1);
	}
	return (0);
}