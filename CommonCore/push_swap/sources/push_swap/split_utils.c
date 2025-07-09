/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:36:23 by bpiovano          #+#    #+#             */
/*   Updated: 2025/07/08 16:23:12 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		++(*cursor);
	while ((s[*cursor + len] != c) && s[*cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[*cursor] != c) && s[*cursor])
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	fill_split_result(char **result_array, char *s, char c, int words_count)
{
	int	i;
	int	cursor;

	i = 0;
	cursor = 0;
	while (words_count-- > 0)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
			return (i);
		i++;
	}
	result_array[i] = NULL;
	return (0);
}
