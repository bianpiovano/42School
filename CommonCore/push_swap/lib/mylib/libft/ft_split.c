/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:22:14 by bpiovano          #+#    #+#             */
/*   Updated: 2025/07/06 15:55:31 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mylib.h"

static int	word_count(const char *str, char c);
static char	*fill_word(const char *str, int start, int end);
static void	*ft_free(char **strs, int count);
static void	ft_initiative_vars(size_t *i, int *j, int *s_word);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		s_word;

	ft_initiative_vars(&i, &j, &s_word);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			res[j] = fill_word(s, s_word, i);
			if (!(res[j]))
				return (ft_free(res, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}

static void	ft_initiative_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}
/*
* Takes :
* a string to be split (s)
* a delimiter character (c)
* Allocates and returns an array of strings obtained
* by splitting s using the character c as a delimiter
* Returns null if the allocation fails
* The array must end with a null pointer
* (Reminder to use free after this function)
* Returns an array of pointers to char
*/
