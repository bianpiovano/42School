/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:04:59 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/04 19:50:20 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

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
* Takes : a pointer to a string (const char) (s)
* Duplicates one string creating a new string
* Assigns memory for the new string / if it fails returns null
* Returns : a pointer to the new string
*/