/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:02:27 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/08 15:02:39 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printhe(unsigned long n)
{
	int	count;
	unsigned long div;
	unsigned long mod;
	static char *symbols = "0123456789abcdef";

	count = 0;

	if (n >= 16)
	{
		div = n / 16;
		mod = n % 16;
		count += printhe(div);
		count += printch(symbols[mod]);
	}
	else
		count += printch(symbols[n % 16]);
	return (count);
}