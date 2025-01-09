/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:12:41 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/12 16:38:37 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
	}
	return (0);
}
/*
* Takes : 
* a pointer to a string of characters (s1)
* a pointer to a string of characters (s2)
* a size number (n)
* Compares the first n bytes (unsigned char)
* of the memory areas s1 and s2
* Returns 0 when values are equal
* Returns : value less than 0 when 1st
* different byte in both memory buffers is less in s1 than s1
* Returns : value greater than 0 when s1 is bigger than s2
*/