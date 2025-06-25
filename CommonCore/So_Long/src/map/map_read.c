/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:20:06 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 18:47:23 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		write(2, "Error:failed to open file.\n", 29);
	return (fd);
}

int	read_map_lines(char **line, int fd, int *width, int *height)
{
	int		line_len;
	int		flag;

	flag = 0;
	line_len = ft_strlen(*line);
	if ((*line)[line_len - 1] == '\n')
		line_len--;
	if (line_len != *width)
		flag = -1;
	(*height)++;
	free(*line);
	*line = get_next_line(fd);
	return (flag);
}

int	calculate_map_dimensions(const char *filename, int *width, int *height)
{
	int		fd;
	char	*line;
	int		flag;

	fd = open_map_file(filename);
	if (fd == -1)
		return (-1);
	*height = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	*width = ft_strlen(line);
	if (line[*width - 1] == '\n')
		(*width)--;
	flag = 0;
	while (line)
		flag = read_map_lines(&line, fd, width, height);
	free(line);
	return (flag);
}

char	**read_map(char *filename)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Invalid file.\n", 14);
		return (NULL);
	}
	map = load_map_from_fd(fd);
	close(fd);
	return (map);
}
