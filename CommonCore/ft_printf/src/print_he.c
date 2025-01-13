/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_he.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:02:27 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/11 17:51:22 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_he(unsigned long n)
{
	int				count;
	unsigned long	div;
	unsigned long	mod;
	static char		*symbols = "0123456789abcdef";

	count = 0;
	if (n >= 16)
	{
		div = n / 16;
		mod = n % 16;
		count += print_he(div);
		count += print_ch(symbols[mod]);
	}
	else
		count += print_ch(symbols[n % 16]);
	return (count);
}
