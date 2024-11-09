/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:32:42 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/06 15:46:53 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			last_occurrence = s;
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last_occurrence);
}

/*
Returns a pointer to the last occurrence
of the character C in the string S
(Asigns values and keeps the last one)
*/