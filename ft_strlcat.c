/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:27:30 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/08 20:46:10 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = 0;
	src_len = 0;
	i = 0;
	if ((!src || !dst) && size == 0) 
		return (0);
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
