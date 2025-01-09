/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:57:10 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/07 12:56:27 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int printhm(unsigned int n)
{
	int			count;
	int			div;
	int			mod;
	static char	*symbols = "0123456789ABCDEF";

	count = 0;

	if (n >= 16)
	{
		div = n / 16;
		mod = n % 16;
		count += printhm(div);
		count += printch(symbols[mod]);
	}
	else count += printch(symbols[n]);
	return (count);
}