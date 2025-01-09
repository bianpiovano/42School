/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:04:36 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/08 14:50:59 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printpo(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += printst("(nil)");
	else
	{
		count += printst("0x");
		count += printhe((unsigned long)ptr);
	}
	return (count);
}
