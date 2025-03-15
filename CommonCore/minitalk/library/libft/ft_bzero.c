/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:09:41 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/04 19:48:20 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

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