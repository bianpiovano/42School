/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:34:33 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/04 19:48:58 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
* Takes an int (c)
* Returns 1 if is a printable character
* Returns 0 if it is not 
*/