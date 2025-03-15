/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_po.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:05:37 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/05 20:29:38 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/library.h"

int	print_po(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += print_st("(nil)");
	else
	{
		count += print_st("0x");
		count += print_he((unsigned long)ptr);
	}
	return (count);
}
