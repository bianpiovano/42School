/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:52:41 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/19 21:07:03 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static int	bit;
	static char	c;
	static int	*flag;

	if (!flag)
	{
		bit = 0;
		c = 0;
	}
	flag = &sig;
	if (sig == SIGUSR2)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("        ⠰⡭⡲⠤⠤⢤⠞⣉⣶⡿⡝⡄⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf("⠀⠀⠀⠀⠀⠀⠀⠀⡲⠃⠀⠀⠀⠸⣀⣻⣀⣹⡅⣹⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf("⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠙⠒⣇⣀⠀⠀⠀⠀⠀⠀\n");
	ft_printf("⠀⠀⠀⠀⠀⠀⠈⣉⣯⠀⠸⠀⠀⣠⡀⠀⠺⠀⠀⡧⠆⠀⠀⠀⠀⠀⠀\n");
	ft_printf("⠀⡗⣄⠀⠀⠀⠀⠀⠜⡣⠤⠤⢄⡉⢁⡠⠤⠤⣼⠣⠀⠀⠀⠀⢀⡰⢳\n");
	ft_printf("⠠⡓⠤⠍⠉⠉⠑⠢⡜⠀⠀⠀⠀⠑⠋⠀⠀⠀⠀⢣⠊⠉⣀⠀⡠⠔⣳\n");
	ft_printf("⠀⠹⣖⣂⢈⠉⠃⢀⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠋⢈⠇⢐⠾⠁\n");
	ft_printf("⠀⠀⠀⠁⠊⠉⠈⠁⠈⢷⢄⠀⠀⠀⠀⠀⢀⡠⠊⠀⠉⠈⠉⠉⠉⠀⠀\n");
	ft_printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠲⢄⡤⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ft_printf("───୨ৎ────  ♡   ────୨ৎ────\n");
	ft_printf("The server PID is: %d\n", getpid());
	ft_printf("───୨ৎ────  ♡   ────୨ৎ────\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
