/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:11:54 by bpiovano          #+#    #+#             */
/*   Updated: 2025/07/08 14:11:59 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mylib.h"

int	print_di(int n)
{
	int			count;
	long		num;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += print_ch('-');
		num = -num;
	}
	count += print_un((unsigned int)num);
	return (count);
}
