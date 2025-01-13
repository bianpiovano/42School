#    ╔──────────────────────────────────────────────────────────𐙚⋆°｡
#    │.--.            .  .-. .---.             .                │
#    │|   )   o      _|_ |   |                _|_   o           │
#    │|--'.--..  .--. | -|-  |--- .  . .--. .-.|    .  .-. .--. │
#    │|   |   |  |  | |  |   |    |  | |  |(   |    | (   )|  | │
#    │'   ' -' `-'  `-`-''   '    `--`-'  `-`-'`-'-' `-`-' '  `-│
#  °⋆𐙚──────────────────────────────────────────────────────────╝
#                               ˋ°•*⁀➷  𝓜𝓪𝓴𝓮 𝓕𝓲𝓵𝓮  ✩⋆˚☾

#    ℙ𝕣𝕚𝕟𝕥 𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟𝕤    #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ──── 

SRCS = src/print_ch.c \
src/print_st.c \
src/print_po.c \
src/print_di.c \
src/print_un.c \
src/print_he.c \
src/print_hu.c \
printf/ft_printf.c

OBJS	= ${SRCS:.c=.o}

# ╭───────── · · ୨୧ · · ─────────╮
#  Ｃｏｍｐｉｌａｔｉｏｎ Ｖａｒｉａｂｌｅｓ
# ╰───────── · · ୨୧ · · ─────────╯

INCS	= -Iinclude
NAME	= libftprintf.a
AR	= ar crs
CC	= cc 
RM	= rm -f 
CFLAGS	= -Wall -Wextra -Werror

# Color codes
# ────୨ৎ────
PINK = \033[38;2;255;105;180m
RESET = \033[0m

.c.o:
		@echo "$(PINK)Compiling $<...$(RESET)"
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	cp libft/libft.a ${NAME}
	ar crs ${NAME} ${OBJS} libft/libft.a

#⋆✴︎˚｡⋆✴︎˚｡⋆｡⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✿˚｡⋆⋆✴︎˚⋆✴⋆｡⋆⋆✴︎˚｡⋆✴︎#
#                 Main Commands                 #
#˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧#

# Default target, builds printf
all: ${NAME}

#     ℝ𝕖𝕞𝕠𝕧𝕖 𝕠𝕓𝕛𝕖𝕔𝕥 𝕗𝕚𝕝𝕖𝕤   #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
clean: 
	@echo "$(PINK)Cleaning up object files...$(RESET)"
	$(RM) $(OBJS)

# 𝔽𝕦𝕝𝕝 𝕔𝕝𝕖𝕒𝕟: 𝕣𝕖𝕞𝕠𝕧𝕖 𝕝𝕚𝕓𝕣𝕒𝕣𝕪 𝕗𝕚𝕝𝕖𝕤 𝕒𝕤 𝕨𝕖𝕝𝕝 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

fclean: clean
	@echo "$(PINK)Removing $(NAME)...$(RESET)"
	$(RM) $(NAME)

# ℝ𝕖𝕓𝕦𝕚𝕝𝕕 𝕖𝕧𝕖𝕣𝕪𝕥𝕙𝕚𝕟𝕘 𝕗𝕣𝕠𝕞 𝕤𝕔𝕣𝕒𝕥𝕔𝕙 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
re: fclean all

#⋆✴︎˚｡⋆✴︎˚｡⋆｡⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆✿⋆˚✴⋆✴˚｡⋆⋆✴︎˚⋆✴#
#                 Phony Targets                 #
#˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧#

.PHONY: all clean fclean re bonus

#  ૮ ˶ᵔ ᵕ ᵔ˶ ა                               ✧₊⁺✧₊ ᓚᘏᗢ
