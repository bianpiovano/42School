/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:55:47 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/08 15:15:04 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printun(unsigned int n)
{
	int			count;
	int			div;
	int			mod;
	static char	*digits = "0123456789";

	count = 0;
	div = n / 10;
	mod = n % 10;
	if (n >= 10)
	{
		count += printdi(div);
	}
	count += printch(digits[mod]);
	return (count);
}