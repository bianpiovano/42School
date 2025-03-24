#    ╔────────────────────────────𐙚⋆°｡
#    │.---.       .               │
#    │\___  ,-.   |    ,-. ,-. ,-.│
#    │    \ | |   |    | | | | | |│
#    │`---' `-'   `--' `-' ' ' `-|│
#    │          ~~              ,|│
#    │                          `'│
#  °⋆𐙚────────────────────────────╝
#                          ˋ°•*⁀➷  𝓜𝓪𝓴𝓮 𝓕𝓲𝓵𝓮  ✩⋆˚☾

# ╭───────── · · ୨୧ · · ─────────╮
#  Ｃｏｍｐｉｌａｔｉｏｎ Ｖａｒｉａｂｌｅｓ
# ╰───────── · · ୨୧ · · ─────────╯

NAME		= so_long
CC         	= cc
CFLAGS     	= -Wall -Werror -Wextra
RM         	= rm -rf
LIBS_DIR	= lib

#    𝕄𝕚𝕟𝕚𝕃𝕚𝕓𝕩 ℂ𝕠𝕞𝕡𝕚𝕝𝕒𝕥𝕚𝕠𝕟   #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ──── 
MLX_DIR		= $(LIBS_DIR)/minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_INCS	= -I$(MLX_DIR)
MLX_ADD		= -L$(MLX_DIR) -lmlx -lXext -lX11

#    𝕄𝕪 𝕃𝕚𝕓𝕣𝕒𝕣𝕪 𝔽𝕚𝕝𝕖𝕤    #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ──── 
MYLIB_DIR	= $(LIBS_DIR)/mylib
MYLIB		= $(MYLIB_DIR)/libmylib.a
MYLIB_INCS	= -I$(MYLIB_DIR)
MYLIB_ADD	= -L$(MYLIB_DIR) -lmylib

#    𝔽𝕦𝕟𝕔𝕥𝕚𝕠𝕟 𝔽𝕚𝕝𝕖𝕤    #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ──── 
SRCS 		= src/game/draw.c \
			  src/game/events.c \
			  src/game/game.c \
			  src/game/map.c 

INCS = $(MLX_INCS) \
		$(MYLIB_INCS) \
		-Iinclude

OBJS_DIR	= .objs
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

# 𝘾𝙤𝙡𝙤𝙧 𝘾𝙤𝙙𝙚𝙨
# ────୨ৎ────
PINK = \033[38;2;255;105;180m
RESET = \033[0m

#⋆✴︎˚｡⋆✴︎˚｡⋆｡⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✿˚｡⋆⋆✴︎˚⋆✴⋆｡⋆⋆✴︎˚｡⋆✴︎#
#                 Main Commands                 #
#˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧#

# 𝔻𝕖𝕗𝕒𝕦𝕝𝕥 𝕥𝕒𝕣𝕘𝕖𝕥, 𝕓𝕦𝕚𝕝𝕕𝕤 𝕤𝕠_𝕝𝕠𝕟𝕘 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
all: $(MLX) $(MYLIB) $(NAME) 

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_ADD) $(MYLIB_ADD) -o $(NAME)

#     ℝ𝕖𝕞𝕠𝕧𝕖 𝕠𝕓𝕛𝕖𝕔𝕥 𝕗𝕚𝕝𝕖𝕤   #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
clean: mlx_clean mylib_clean
	@echo "$(PINK)Cleaning up object files...$(RESET)"
	$(RM) $(OBJS)

# 𝔽𝕦𝕝𝕝 𝕔𝕝𝕖𝕒𝕟: 𝕣𝕖𝕞𝕠𝕧𝕖 𝕝𝕚𝕓𝕣𝕒𝕣𝕪 𝕗𝕚𝕝𝕖𝕤 𝕒𝕤 𝕨𝕖𝕝𝕝 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
fclean: mylib_fclean clean
	@echo "$(PINK)Removing $(NAME)...$(RESET)"
	$(RM) $(NAME)

# ℝ𝕖𝕓𝕦𝕚𝕝𝕕 𝕖𝕧𝕖𝕣𝕪𝕥𝕙𝕚𝕟𝕘 𝕗𝕣𝕠𝕞 𝕤𝕔𝕣𝕒𝕥𝕔𝕙 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
re: fclean all

#    𝕄𝕚𝕟𝕚𝕃𝕚𝕓𝕩 𝕣𝕦𝕝𝕖𝕤    #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ──── 
$(MLX):
	make -C $(MLX_DIR) all --no-print-directory;

# ℝ𝕖𝕞𝕠𝕧𝕖 𝕠𝕓𝕛𝕖𝕔𝕥 𝕗𝕚𝕝𝕖𝕤 𝕗𝕣𝕠𝕞 𝕄𝕚𝕟𝕚𝕃𝕚𝕓𝕩 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
mlx_clean:
	make -C $(MLX_DIR) clean;

#  𝕄𝕪 𝕃𝕚𝕓𝕣𝕒𝕣𝕪 𝕣𝕦𝕝𝕖𝕤  #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ──── 
$(MYLIB):
	make -C $(MYLIB_DIR) all --no-print-directory;

#  ℝ𝕖𝕞𝕠𝕧𝕖 𝕞𝕪 𝕝𝕚𝕓𝕣𝕒𝕣𝕪 𝕠𝕓𝕛𝕖𝕔𝕥𝕤  #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
mylib_clean:
	make -C $(MYLIB_DIR) clean --no-print-directory;


# 𝔽𝕦𝕝𝕝 𝕔𝕝𝕖𝕒𝕟: 𝕣𝕖𝕞𝕠𝕧𝕖 𝕞𝕪 𝕝𝕚𝕓𝕣𝕒𝕣𝕪 𝕗𝕚𝕝𝕖𝕤 𝕒𝕤 𝕨𝕖𝕝𝕝 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
mylib_fclean:
	make -C $(MYLIB_DIR) fclean --no-print-directory;

#⋆✴︎˚｡⋆✴︎˚｡⋆｡⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆✿⋆˚✴⋆✴˚｡⋆⋆✴︎˚⋆✴#
#                 Phony Targets                 #
#˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧#

.PHONY: all clean fclean re

#  ૮ ˶ᵔ ᵕ ᵔ˶ ა                               ✧₊⁺✧₊ ᓚᘏᗢ