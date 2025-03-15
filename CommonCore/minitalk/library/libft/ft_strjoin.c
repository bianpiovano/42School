/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:16:55 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/04 19:50:30 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}
/*
* Takes :
* a pointer to the prefix string (s1)
* a pointer to the suffix string (s2) 
* Allocates and returns a new string,
* which is the result of the concatenation(s1 and s2)
* Returns null if the allocation fails
* Returns : the substring
*/