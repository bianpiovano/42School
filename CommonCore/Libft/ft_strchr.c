/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:14:01 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/12 16:10:23 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
/*
* Takes :
* a pointer to a string of characters (s)
* an int as character to be searched (c)
* Searches for a character 
* Returns a pointer to the first occurrence 
* of the character c in the string s 
* (turned into a char *)
* If the character searched is “\0”
* it returns a pointer to the end of the string
* if it doesn’t find the character, returns null
*/
