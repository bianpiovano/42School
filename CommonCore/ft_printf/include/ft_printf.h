/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:10:46 by bpiovano          #+#    #+#             */
/*   Updated: 2025/01/13 19:55:40 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//    ╔──────────────────────────────────────────────────────────𐙚⋆°｡
//    │.--.            .  .-. .---.             .                │
//    │|   )   o      _|_ |   |                _|_   o           │
//    │|--'.--..  .--. | -|-  |--- .  . .--. .-.|    .  .-. .--. │
//    │|   |   |  |  | |  |   |    |  | |  |(   |    | (   )|  | │
//    │'   ' -' `-'  `-`-''   '    `--`-'  `-`-'`-'-' `-`-' '  `-│
//  °⋆𐙚──────────────────────────────────────────────────────────╝
//                               ˋ°•*⁀➷ 𝓗𝓮𝓪𝓭𝓮𝓻 𝓕𝓲𝓵𝓮 ✩⋆˚☾
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//  ────── ⑅ ♡ ⑅  ──────
//•°¯`•• 𝕃𝕚𝕓𝕣𝕒𝕣𝕚𝕖𝕤 ••`¯°•//
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

# include "../libft/libft.h"
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h> 
# include <stdint.h>
# include <limits.h>

//  ────── ⑅ ♡ ⑅  ──────
//  𝕄𝕪 ℙ𝕣𝕚𝕟𝕥𝕚𝕟𝕘 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤  //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

int	print_ch(int c);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓
int	print_st(char *str);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒔𝒕𝒓𝒊𝒏𝒈
int	print_po(void *ptr);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒑𝒐𝒊𝒏𝒕𝒆𝒓
int	print_di(int n);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒅𝒊𝒈𝒊𝒕
int	print_un(unsigned int n);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒖𝒏𝒔𝒊𝒈𝒏𝒆𝒅 𝒊𝒏𝒕
int	print_he(unsigned long n);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒉𝒆𝒙𝒂𝒅𝒆𝒄𝒊𝒎𝒂𝒍
int	print_hu(unsigned int n);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒉𝒆𝒙𝒂𝒅𝒆𝒄𝒊𝒎𝒂𝒍 (𝐮𝐩𝐩𝐞𝐫𝐜𝐚𝐬𝐞)
int	my_format(char formatsp, va_list *input);
// ╰┈➤ 𝒇𝒐𝒓𝒎𝒂𝒕 𝒉𝒂𝒏𝒅𝒍𝒆𝒓

//  ────── ⑅ ♡ ⑅  ──────
//   ℂ𝕠𝕣𝕖 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟   //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
int	ft_printf(const char *format, ...);
// ╰┈➤ 𝐩𝐫𝐢𝐧𝐭𝐟

#endif

//  ૮ ˶ᵔ ᵕ ᵔ˶ ა                               ✧₊⁺✧₊ ᓚᘏᗢ