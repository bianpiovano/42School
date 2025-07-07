/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:32:42 by bpiovano          #+#    #+#             */
/*   Updated: 2025/07/06 15:55:31 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mylib.h"

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
* Takes : 
* a pointer to a string of characters (s)
* an int as character to be searched (c)
* Searches for a character
* Returns a pointer to the last occurrence 
* of the character c in the string s (turned into a char *)
* If the character searched is “\0” 
* it returns a pointer to the end of the string
* if it doesn’t find the character, returns null
*/