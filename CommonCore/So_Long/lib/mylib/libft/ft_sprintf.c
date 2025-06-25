/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:08:25 by bpiovano          #+#    #+#             */
/*   Updated: 2025/06/24 17:22:11 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write_str(char *dst, const char *src)
{
	int	i;

	if (!src)
		src = "(null)";
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

static int	ft_write_char(char *dst, char c)
{
	dst[0] = c;
	return (1);
}

static int	ft_write_int(char *dst, int n)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 0;
	num = n;
	if (num < 0)
	{
		dst[i++] = '-';
		num = -num;
		sign = 1;
	}
	if (num >= 10)
		i += ft_write_int(dst + i, num / 10);
	dst[i++] = (num % 10) + '0';
	dst[i] = '\0';
	return (i);
}

static int	handle_format(const char *fmt, va_list args, char *dst)
{
	if (*fmt == 's')
		return (ft_write_str(dst, va_arg(args, char *)));
	if (*fmt == 'd')
		return (ft_write_int(dst, va_arg(args, int)));
	if (*fmt == 'c')
		return (ft_write_char(dst, (char)va_arg(args, int)));
	return (0);
}

int	ft_sprintf(char *str, const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start(args, fmt);
	i = 0;
	j = 0;
	while (fmt && fmt[i])
	{
		if (fmt[i] == '%' && (fmt[i + 1] == 's' || fmt[i + 1] == 'd' || fmt[i
					+ 1] == 'c'))
		{
			j += handle_format(&fmt[i + 1], args, &str[j]);
			i += 2;
		}
		else
		{
			str[j++] = fmt[i++];
		}
	}
	str[j] = '\0';
	va_end(args);
	return (j);
}
