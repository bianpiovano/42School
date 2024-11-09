/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:46:58 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/06 15:44:25 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}

/*
Copies n bytes from memory area src to memory area dest.
The memory areas may overlap: copying takes place as though 
	the bytes in src are first copied into a temporary array 
	that does not overlap src or dest,
	and the bytes are then copied from the temporary array to dest.
Returns a pointer to dest.
*/