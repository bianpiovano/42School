/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:09:38 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/11 17:51:06 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_hu(unsigned int n)
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
		count += print_hu(div);
		count += print_ch(symbols[mod]);
	}
	else
		count += print_ch(symbols[n]);
	return (count);
}
