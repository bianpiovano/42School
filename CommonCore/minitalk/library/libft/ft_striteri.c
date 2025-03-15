/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:18:03 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/04 19:50:25 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
 * Takes :
 * a string on which to iterate (s)
 * a function to apply to each character(f)
 * Does not return anything (compared to strmapi)
 * Applies the function f on each character of the string
 * passed as argument, passing its index as first argument
 * Each character is passed by address to f to be modified if necessary
 */