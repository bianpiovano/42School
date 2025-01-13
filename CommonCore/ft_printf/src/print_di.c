/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:32 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/11 22:19:27 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_di(int n)
{
	int			count;

	count = 0;
	if (n < 0)
	{
		count += print_ch('-');
		n = -n;
	}
	count += print_un(n);
	return (count);
}
