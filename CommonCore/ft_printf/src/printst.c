/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:00:28 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/06 19:48:16 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	printst(char *str)
{
	int count;

	count = 0;
	if (str == NULL)
		return (printst("(null)"));
	while (*str)
	{
		count += printch((int)*str);
		str++;
	}
	return (count);
}