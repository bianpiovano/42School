/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:51:20 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/08 21:12:23 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	unsigned char	*tmp;
	size_t			total;
	size_t			i;

	total = nmeb * size;
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
Allocates memory for an array of nmeb elements
of size bytes each and returns a pointer to
the allocated memory. The memory is set to 0.
*/