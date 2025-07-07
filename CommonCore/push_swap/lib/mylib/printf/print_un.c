/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:55:47 by bpiovano          #+#    #+#             */
/*   Updated: 2025/07/06 15:55:31 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mylib.h"

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
