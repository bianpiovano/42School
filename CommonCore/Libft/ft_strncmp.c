/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:38:42 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/08 20:34:10 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && (*s1 == *s2) && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
Compares two strings.
Only the first (at most) C bytes of s1 and s2
Returns an integer indicating the result of the comparison
0 if values are equal
negative value if s1 is less than s2
positive value if s1 is greater than s2
*/
