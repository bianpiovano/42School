/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:57:31 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/08 20:49:54 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_len;
	size_t	i;

	if ((!big || !little) && len == 0)
		return (0);
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	i = 0;
	if (little_len == 0)
		return ((char *)big);
	while (i + little_len <= len && i + little_len <= big_len)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
Locates the first occurrence of the nterminated string
little in the string big, where not more than Len
characters are searched.
*/