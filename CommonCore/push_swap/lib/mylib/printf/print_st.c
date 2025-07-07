/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:00:28 by bpiovano          #+#    #+#             */
/*   Updated: 2025/07/06 15:55:31 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mylib.h"

int	print_st(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (print_st("(null)"));
	while (*str)
	{
		count += print_ch((int)*str);
		str++;
	}
	return (count);
}
