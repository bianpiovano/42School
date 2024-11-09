/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:04:59 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/06 15:45:28 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		length;
	char	*duplicate;

	i = 0;
	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	duplicate = (char *)malloc((length + 1));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	while (i < length)
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

/*
Returns a pointer to a new string which is a
duplicate of the string s.
Memory for the new string is obtained with malloc(3)
*/