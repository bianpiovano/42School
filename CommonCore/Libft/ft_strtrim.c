/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:37:07 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/06 15:47:08 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(const char *set, char c);
static char	*new_str(const char *s1, size_t start, size_t end);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
	{
		return (ft_strdup(""));
	}
	while (to_trim(set, s1[i]))
	{
		i++;
	}
	while (to_trim(set, s1[j]))
	{
		j--;
	}
	return (new_str(s1, i, j - (i - 1)));
}

static char	*new_str(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
	{
		return (ft_strdup(""));
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

static int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/*
to_trim: compares each character to set
returns 1 if equal, 0 if there is no coincidence

new_str: creates a new string copying a specific
section of s1 (start and length)

strtrim: gets s1 length, loops at the beginning 
and end of s1. Returns a new string.
*/