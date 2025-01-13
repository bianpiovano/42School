/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:55:47 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/11 22:25:41 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_un(unsigned int n)
{
	int				count;
	int				div;
	int				mod;
	static char		*digits;
	
	digits = "0123456789";
	count = 0;
	div = n / 10;
	mod = n % 10;
	if (n >= 10)
	{
		count += print_di(div);
	}
	count += print_ch(digits[mod]);
	return (count);
}
