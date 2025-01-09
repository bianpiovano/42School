/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:32 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/08 15:38:07 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printdi(int n)
{
	int			count;

	count = 0;
	if (n < 0)
	{
		count += printch('-');
		n = -n;
	}
	count += printun(n);
	return (count);
}
