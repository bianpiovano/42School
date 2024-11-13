/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:58:15 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/12 15:39:51 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void *)ptr);
		}
		ptr++;
	}
	return (NULL);
}
/*
* Takes :
* a pointer to a string of characters (s)
* an int (c)
* a size number (n)
* Searches the first occurrence of a character c in
* the first n bytes of a block of memory pointed to by s
* The search continues until it finds c or examines count bytes
* It doesn’t stop at a null terminator
* Converting to unsigned char is important to ensure
* that values ​​are compared correctly on a byte-by-byte basis
* Returns : a pointer to the byte of memory found
*/
