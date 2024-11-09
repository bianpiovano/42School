/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:58:15 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/06 15:43:11 by bpiovano         ###   ########.fr       */
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
Searches the first count bytes of buf
for the first occurrence of C converted
to an unsigned character. The search continues until
it finds C or examines count bytes
*/
