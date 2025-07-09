/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:17:34 by bpiovano          #+#    #+#             */
/*   Updated: 2025/07/08 15:10:06 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

//    ╔───────────────────────────────────────────𐙚⋆°｡
//    │.    .     .         .                     │
//    │|\  /|     |      o  |                     │
//    │| \/ |.  . |      .  |.-. .--..-.  .--..  .│
//    │|    ||  | |      |  |   )|  (   ) |   |  |│
//    │'    '`--| '---'-' `-'`-' '   `-'`-'   `--|│
//    │         ;                                ;│
//    │      `-'                              `-' │
//  °⋆𐙚───────────────────────────────────────────╝
//                               ˋ°•*⁀➷ 𝓗𝓮𝓪𝓭𝓮𝓻 𝓕𝓲𝓵𝓮 ✩⋆˚☾

//  ────── ⑅ ♡ ⑅  ──────
//•°¯`•• 𝕃𝕚𝕓𝕣𝕒𝕣𝕚𝕖𝕤 ••`¯°•//
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>

//    ╔──────────────────────────────────────────────────────𐙚⋆°｡
//    │.         .    .-..   .         .                     │
//    │|      o  |    | _|_  |      o  |                     │
//    │|      .  |.-.-|- |   |      .  |.-. .--..-.  .--..  .│
//    │|      |  |   )|  |   |      |  |   )|  (   ) |   |  |│
//    │'---'-' `-'`-' '  `-' '---'-' `-'`-' '   `-'`-'   `--|│
//    │                                                     ;│
//    │                                                  `-' │
//  °⋆𐙚──────────────────────────────────────────────────────╝
//                               ˋ°•*⁀➷ 𝓕𝓾𝓷𝓬𝓽𝓲𝓸𝓷𝓼 ✩⋆˚☾

//  ────── ⑅ ♡ ⑅  ──────
// 𝕊𝕥𝕣𝕚𝕟𝕘 𝕄𝕒𝕟𝕚𝕡𝕦𝕝𝕒𝕥𝕚𝕠𝕟 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
unsigned int	ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

//  ────── ⑅ ♡ ⑅  ──────
//•°¯`•• 𝕄𝕖𝕞𝕠𝕣𝕪 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 ••`¯°•//
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t nmeb, size_t size);

//  ────── ⑅ ♡ ⑅  ──────
// ℂ𝕙𝕒𝕣𝕒𝕔𝕥𝕖𝕣 ℂ𝕙𝕖𝕔𝕜 𝕒𝕟𝕕 ℂ𝕠𝕟𝕧𝕖𝕣𝕤𝕚𝕠𝕟 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

//  ────── ⑅ ♡ ⑅  ──────
// ℂ𝕠𝕟𝕧𝕖𝕣𝕤𝕚𝕠𝕟 𝕒𝕟𝕕 𝕌𝕥𝕚𝕝𝕚𝕥𝕪 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);

//  ────── ⑅ ♡ ⑅  ──────
//•°¯`•• 𝔽𝕚𝕝𝕖 𝔻𝕖𝕤𝕔𝕣𝕚𝕡𝕥𝕠𝕣 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 ••`¯°•//
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

//  ────── ⑅ ♡ ⑅  ──────
//•°¯`•• 𝕄𝕪 𝔼𝕩𝕥𝕣𝕒 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 ••`¯°•//
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

void			ft_putchar(char c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_sprintf(char *str, const char *fmt, ...);

//    ╔──────────────────────────────────────────────────────────𐙚⋆°｡
//    │.--.            .  .-. .---.             .                │
//    │|   )   o      _|_ |   |                _|_   o           │
//    │|--'.--..  .--. | -|-  |--- .  . .--. .-.|    .  .-. .--. │
//    │|   |   |  |  | |  |   |    |  | |  |(   |    | (   )|  | │
//    │'   ' -' `-'  `-`-''   '    `--`-'  `-`-'`-'-' `-`-' '  `-│
//  °⋆𐙚──────────────────────────────────────────────────────────╝
//                               ˋ°•*⁀➷ 𝓕𝓾𝓷𝓬𝓽𝓲𝓸𝓷𝓼 ✩⋆˚☾

//  ────── ⑅ ♡ ⑅  ──────
//  𝕄𝕪 ℙ𝕣𝕚𝕟𝕥𝕚𝕟𝕘 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤  //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

int				print_ch(int c);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓
int				print_st(char *str);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒔𝒕𝒓𝒊𝒏𝒈
int				print_po(void *ptr);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒑𝒐𝒊𝒏𝒕𝒆𝒓
int				print_di(int n);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒅𝒊𝒈𝒊𝒕
int				print_un(unsigned int n);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒖𝒏𝒔𝒊𝒈𝒏𝒆𝒅 𝒊𝒏𝒕
int				print_he(unsigned long n);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒉𝒆𝒙𝒂𝒅𝒆𝒄𝒊𝒎𝒂𝒍
int				print_hu(unsigned int n);
// ╰┈➤ 𝒑𝒓𝒊𝒏𝒕 𝒉𝒆𝒙𝒂𝒅𝒆𝒄𝒊𝒎𝒂𝒍 (𝐮𝐩𝐩𝐞𝐫𝐜𝐚𝐬𝐞)
int				my_format(char formatsp, va_list *input);
// ╰┈➤ 𝒇𝒐𝒓𝒎𝒂𝒕 𝒉𝒂𝒏𝒅𝒍𝒆𝒓

//  ────── ⑅ ♡ ⑅  ──────
//   ℂ𝕠𝕣𝕖 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟   //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
int				ft_printf(const char *format, ...);
// ╰┈➤ 𝐩𝐫𝐢𝐧𝐭𝐟

//    ╔────────────────────────────────────────────────────𐙚⋆°｡
//    │ .--.     .   .   .          .   .                  │
//    │:        _|_  |\  |         _|_  |      o           │
//    │| --. .-. |   | \ | .-. -. ,-|   |      .  .--. .-. │
//    │:   |(.-' |   |  \|(.-'   :  |   |      |  |  |(.-' │
//    │ `--' `--'`-' '   ' `--'-' `-`-' '---'-' `-'  `-`--'│
//  °⋆𐙚────────────────────────────────────────────────────╝
//                               ˋ°•*⁀➷ 𝓕𝓾𝓷𝓬𝓽𝓲𝓸𝓷𝓼 ✩⋆˚☾

//  ────── ⑅ ♡ ⑅  ──────
// 𝕄𝕪 𝔹𝕦𝕗𝕗𝕖𝕣 𝔾𝕝𝕠𝕓𝕒𝕝 𝕍𝕒𝕣𝕚𝕒𝕓𝕝𝕖
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//  ────── ⑅ ♡ ⑅  ──────
// 𝔽𝕚𝕝𝕖 𝕒𝕟𝕕 𝔹𝕦𝕗𝕗𝕖𝕣 𝕄𝕒𝕟𝕒𝕘𝕖𝕞𝕖𝕟𝕥 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
char			*read_from_file(char *buffer2, int fd);
// ╰┈➤ 𝒓𝒆𝒂𝒅 𝒅𝒂𝒕𝒂 (𝒎𝒂𝒏𝒚 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓𝒔 𝒂𝒔 𝒃𝒖𝒇𝒇𝒆𝒓_𝒔𝒊𝒛𝒆)
char			*extract_line(char *buffer2);
// ╰┈➤ 𝒆𝒙𝒕𝒓𝒂𝒄𝒕 𝒕𝒉𝒆 𝒍𝒊𝒏𝒆 𝒇𝒓𝒐𝒎 𝒕𝒉𝒆 𝒓𝒆𝒂𝒅 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓𝒔
char			*obtain_remaining(char *buffer2);
// ╰┈➤ 𝒔𝒕𝒐𝒓𝒆𝒔 𝒕𝒉𝒆 𝒓𝒆𝒎𝒂𝒊𝒏𝒊𝒏𝒈
char			*append_buffer(char *buffer2, char *read_buffer);
// ╰┈➤ 𝒑𝒖𝒕 𝒔𝒕𝒓𝒊𝒏𝒈𝒔 𝒕𝒐𝒈𝒆𝒕𝒉𝒆𝒓

//  ────── ⑅ ♡ ⑅  ──────
//   𝕌𝕥𝕚𝕝𝕚𝕥𝕪 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤   //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
char			*ft_strchr(const char *s, int c);
// ╰┈➤ 𝒔𝒆𝒂𝒓𝒄𝒉 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓 (𝒊𝒏 𝒔𝒕𝒓𝒊𝒏𝒈)
char			*ft_strjoin(char const *s1, char const *s2);
// ╰┈➤ 𝒔𝒕𝒓𝒊𝒏𝒈 𝒋𝒐𝒊𝒏
void			*ft_calloc(size_t nmeb, size_t size);
// ╰┈➤ 𝒂𝒍𝒍𝒐𝒄𝒂𝒕𝒆 𝒎𝒆𝒎𝒐𝒓𝒚
size_t			ft_strlen(const char *str);
// ╰┈➤ 𝒄𝒂𝒍𝒄𝒖𝒍𝒂𝒕𝒆 𝒔𝒕𝒓𝒊𝒏𝒈 𝒍𝒆𝒏𝒈𝒕𝒉
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
// ╰┈➤ 𝒄𝒐𝒑𝒚 𝒂𝒏𝒅 𝒄𝒐𝒏𝒄𝒂𝒕𝒆𝒏𝒂𝒕𝒆 𝒔𝒕𝒓𝒊𝒏𝒈

//  ────── ⑅ ♡ ⑅  ──────
//   ℂ𝕠𝕣𝕖 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟   //
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
char			*get_next_line(int fd);
// ╰┈➤ 𝒈𝒆𝒕 𝒏𝒆𝒙𝒕 𝒍𝒊𝒏𝒆

#endif
//  ૮ ˶ᵔ ᵕ ᵔ˶ ა                               ✧₊⁺✧₊ ᓚᘏᗢ
