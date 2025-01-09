/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:01:13 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/06 20:18:16 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h" 

int	ft_printf(const char *format, ...)
{
	va_list	input;
	int		count;

	va_start(input, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += myformat(*++format, &input);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(input);
	return (count);
}
int	myformat(char formatsp, va_list *input)
{
	int	count;

	count = 0;
	if (formatsp == 'c')
		count += printch(va_arg(*input, int));
	else if (formatsp == 's')
		count += printst(va_arg(*input, char *));
	else if (formatsp == 'p')
		count += printpo(va_arg(*input, void *));
	else if (formatsp == 'd' || formatsp == 'i')
		count += printdi(va_arg(*input, int));
	else if (formatsp == 'u')
		count += printun(va_arg(*input, unsigned int));
	else if (formatsp == 'x')
		count += printhe(va_arg(*input, unsigned int));
	else if (formatsp == 'X')
		count += printhm(va_arg(*input, unsigned int));
	else
		count += write(1, &formatsp, 1);
	return (count);
}