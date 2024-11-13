/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:51:20 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/13 14:19:48 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (nmeb != 0 && size > __SIZE_MAX__ / nmeb)
		return (0);
	tmp = malloc(nmeb * size);
	if (!tmp)
	{
		return (NULL);
	}
	while (i < nmeb * size)
	{
		tmp[i++] = 0;
	}
	return (tmp);
}
/*
 * Takes :
 * a size number of elements to assign (nmeb)
 * a size in bytes of each element (size)
 * Allocates memory for an array of nmeb elements of size
 * bytes each and returns a pointer to the allocated memory
 * The memory is set to 0.
 * If the assignment fails, it returns null
 * Returns : a pointer to the memory assigned
 */