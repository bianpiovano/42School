/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:10:46 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/08 15:08:10 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h> 
# include <stdint.h>
# include <limits.h>

int printch(int);
int printst(char *);
int printpo(void *);
int printdi(int);
int printun(unsigned int);
int printhe(uintptr_t);
int printhm(unsigned int);
int myformat(char formatsp, va_list *input);
int ft_printf(const char *format, ...);
#endif 