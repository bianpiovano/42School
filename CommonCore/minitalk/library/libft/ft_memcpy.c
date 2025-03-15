/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:11:13 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/04 19:49:16 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
/*
* Takes :
* a pointer to source memory area (src)
* a pointer to destiny memory area (dest)
* Copies n bytes from memory area (src) to memory area (dest)
* The memory areas must not overlap
* Returns : a pointer to dest
*/
