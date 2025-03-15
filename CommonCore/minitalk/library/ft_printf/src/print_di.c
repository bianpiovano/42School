/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:32 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/05 20:28:43 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/library.h"

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
