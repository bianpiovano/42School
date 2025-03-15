/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:04:57 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/04 19:49:28 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}
/*
* Takes :
* a pointer to the block of memory to fill (s)
* a value to fill up the memory (c ) 
* a size number of bytes to be occupied (n) 
* Fills the first n bytes of the memory area 
* pointed to by s with the constant byte c
* Returns : a pointer to the memory area s
*/