/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:52:36 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/08 17:56:39 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	pid_t server_pid = ft_atoi(argv[1]);
	char *message = argv[2];

	if (server_pid < 0)
	{
		write(2, "Please insert a valid PID ", 26);
		write(2, "\u2661\n", 4);
		return (1);
	} 

	while (*message)
	{
		send_char(server_pid, *message);
		usleep(1000);
		message++;
	}
	send_char(server_pid, '\n');
	return (0);
}