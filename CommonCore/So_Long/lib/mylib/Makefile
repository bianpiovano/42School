#    ╔───────────────────────────────────────────𐙚⋆°｡
#    │,-,-,-.          .      .                  │
#    │`,| | |   . .    |    . |-. ,-. ,-. ,-. . .│
#    │  | ; | . | |    |    | | | |   ,-| |   | |│
#    │  '   `-' `-|    `--' ' `-' '   `-^ '   `-|│
#    │           /|                            /|│
#    │          `-'                           `-'│
#  °⋆𐙚───────────────────────────────────────────╝
#                          ˋ°•*⁀➷  𝓜𝓪𝓴𝓮 𝓕𝓲𝓵𝓮  ✩⋆˚☾

CC = cc
LIBCC = ar rcs
NAME = libmylib.a 

RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

# 𝕊𝕥𝕣𝕚𝕟𝕘 𝕄𝕒𝕟𝕚𝕡𝕦𝕝𝕒𝕥𝕚𝕠𝕟 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
STR_SRCS = libft/ft_strlen.c \
           libft/ft_strlcpy.c \
           libft/ft_strlcat.c \
           libft/ft_strchr.c \
           libft/ft_strrchr.c \
           libft/ft_strncmp.c \
           libft/ft_strnstr.c \
           libft/ft_strdup.c \
           libft/ft_substr.c \
           libft/ft_strjoin.c \
           libft/ft_strtrim.c \
           libft/ft_split.c \
           libft/ft_strmapi.c \
           libft/ft_striteri.c

#•°¯`•• 𝕄𝕖𝕞𝕠𝕣𝕪 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 ••`¯°•#
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
MEM_SRCS = libft/ft_bzero.c \
           libft/ft_memcpy.c \
           libft/ft_memset.c \
           libft/ft_memmove.c \
           libft/ft_memchr.c \
           libft/ft_memcmp.c \
           libft/ft_calloc.c

# ℂ𝕙𝕒𝕣𝕒𝕔𝕥𝕖𝕣 ℂ𝕙𝕖𝕔𝕜 𝕒𝕟𝕕 ℂ𝕠𝕟𝕧𝕖𝕣𝕤𝕚𝕠𝕟 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
CHAR_SRCS = libft/ft_isalnum.c \
            libft/ft_isalpha.c \
            libft/ft_isascii.c \
            libft/ft_isdigit.c \
            libft/ft_isprint.c \
            libft/ft_toupper.c \
            libft/ft_tolower.c

# ℂ𝕠𝕟𝕧𝕖𝕣𝕤𝕚𝕠𝕟 𝕒𝕟𝕕 𝕌𝕥𝕚𝕝𝕚𝕥𝕪 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
UTIL_SRCS = libft/ft_atoi.c \
            libft/ft_itoa.c

#•°¯`•• 𝔽𝕚𝕝𝕖 𝔻𝕖𝕤𝕔𝕣𝕚𝕡𝕥𝕠𝕣 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤 ••`¯°•#
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
FD_SRCS = libft/ft_putchar_fd.c \
          libft/ft_putstr_fd.c \
          libft/ft_putendl_fd.c \
          libft/ft_putnbr_fd.c

# get next line
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
GNL_SRCS = get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

# ℂ𝕠𝕞𝕓𝕚𝕟𝕖 𝕒𝕝𝕝 𝕤𝕠𝕦𝕣𝕔𝕖 𝕗𝕚𝕝𝕖𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
SRCS = $(STR_SRCS) $(MEM_SRCS) $(CHAR_SRCS) $(UTIL_SRCS) $(FD_SRCS) $(GNL_SRCS)
OBJS = $(SRCS:.c=.o)

all: ${NAME}

.c.o:
	${CC} $< -o $@ -c ${CFLAGS}

${NAME}: ${OBJS}
	${LIBCC} ${NAME} ${OBJS}

clean: 
	@echo "$(PINK)Cleaning up object files...$(RESET)"
	$(RM) $(OBJS)

fclean: clean
	@echo "$(PINK)Removing $(NAME)...$(RESET)"
	$(RM) $(NAME)

re: fclean all

#⋆✴︎˚｡⋆✴︎˚｡⋆｡⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆✿⋆˚✴⋆✴˚｡⋆⋆✴︎˚⋆✴#
#                 Phony Targets                 #
#˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧#

.PHONY: all clean fclean re

#  ૮ ˶ᵔ ᵕ ᵔ˶ ა                               ✧₊⁺✧₊ ᓚᘏᗢ
