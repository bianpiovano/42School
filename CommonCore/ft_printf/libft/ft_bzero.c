/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:09:41 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/12 15:17:37 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}
/*
* Takes :
* a pointer to the block of memory (s)
* a size number of bytes to be erased (n)
* Erases the data in the n bytes of the memory 
* starting at the location pointed to by s,
* by writing zeros (bytes containing '\0') to that area.
*/