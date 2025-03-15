/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:56:54 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/04 19:48:41 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/*
* Takes an int (c)
* Returns 1 if is an alphabetic character
* Returns 0 if it is not 
*/