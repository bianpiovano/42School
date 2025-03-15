/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:01:13 by bpiovano          #+#    #+#             */
/*   Updated: 2025/02/05 20:28:04 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/library.h"

int	ft_printf(const char *format, ...)
{
	va_list	input;
	int		count;

	va_start(input, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += my_format(*++format, &input);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(input);
	return (count);
}

int	my_format(char formatsp, va_list *input)
{
	int	count;

	count = 0;
	if (formatsp == 'c')
		count += print_ch(va_arg(*input, int));
	else if (formatsp == 's')
		count += print_st(va_arg(*input, char *));
	else if (formatsp == 'p')
		count += print_po(va_arg(*input, void *));
	else if (formatsp == 'd' || formatsp == 'i')
		count += print_di(va_arg(*input, int));
	else if (formatsp == 'u')
		count += print_un(va_arg(*input, unsigned int));
	else if (formatsp == 'x')
		count += print_he(va_arg(*input, unsigned int));
	else if (formatsp == 'X')
		count += print_hu(va_arg(*input, unsigned int));
	else
		count += write(1, &formatsp, 1);
	return (count);
}
