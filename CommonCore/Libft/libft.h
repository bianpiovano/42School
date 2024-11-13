/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpiovano <bpiovano@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:42:31 by bpiovano          #+#    #+#             */
/*   Updated: 2024/11/13 15:56:15 by bpiovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°☆⋆⋆｡𖦹°‧☆//
//                                               //
//                                               //
//           𐙚 𝓗𝓮𝓪𝓭𝓮𝓻𝓯𝓲𝓵𝓮 𝓛𝓲𝓫𝓯𝓽 𝓛𝓲𝓫𝓻𝓪𝓻𝔂 𐙚‧            //
//                                               //
//                                               //
//☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧⋆｡𖦹°‧☆//

#ifndef LIBFT_H
# define LIBFT_H

//  ────── ⑅ ♡ ⑅  ──────
//•°¯`•• 𝕃𝕚𝕓𝕣𝕒𝕣𝕚𝕖𝕤 ••`¯°•//
//  ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

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

#endif
