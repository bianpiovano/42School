#    ╔──────────────────────────────────𐙚⋆°｡
#    │,-,-,-.            ,--,--'  .  .  │
#    │`,| | |   . ,-. .  `- | ,-. |  | ,│
#    │  | ; | . | | | |   , | ,-| |  |< │
#    │  '   `-' ' ' ' '   `-' `-^ `' ' `│
#  °⋆𐙚──────────────────────────────────╝
#                               ˋ°•*⁀➷  𝓜𝓪𝓴𝓮 𝓕𝓲𝓵𝓮  ✩⋆˚☾

# 𝕋𝕒𝕣𝕘𝕖𝕥𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
SERVER = server
CLIENT = client
NAME	= MiniTalk

# 𝔻𝕚𝕣𝕖𝕔𝕥𝕠𝕣𝕚𝕖𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
OBJ_DIR = objs
LIB_DIR = library 

# 𝕊𝕠𝕦𝕣𝕔𝕖 𝔽𝕚𝕝𝕖𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c

# 𝕆𝕓𝕛𝕖𝕔𝕥 𝔽𝕚𝕝𝕖𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
SERVER_OBJ = $(SERVER_SRC:%.c=$(OBJ_DIR)/$(SERVER)/%.o)
CLIENT_OBJ = $(CLIENT_SRC:%.c=$(OBJ_DIR)/$(CLIENT)/%.o)

# ╭───────── · · ୨୧ · · ─────────╮
#  Ｃｏｍｐｉｌａｔｉｏｎ Ｖａｒｉａｂｌｅｓ
# ╰───────── · · ୨୧ · · ─────────╯
CC	= cc
CFLAGS = -Wall -Werror -Wextra -g
INCS = -Iinclude
OBJ_DIR = objs
RM	= rm -rf

# 𝕃𝕚𝕓𝕣𝕒𝕣𝕪 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
LIB_DIR = library
LIB_INC = -I $(LIB_DIR)/conversion \
	-I $(LIB_DIR)/char \
	-I $(LIB_DIR)/print
ADD_LIB = -L $(LIB_DIR) -l ft 

MFA_BP_MANDATORY = $(OBJ_DIR)/mfa_bp_mandatory
MFA_MANDATORY_HEADER = $(OBJ_DIR)/mfa_mandatory_header
MFA_LIB_HEADER = $(OBJ_DIR)/mfa_library_header

# 𝕄𝕒𝕟𝕕𝕒𝕥𝕠𝕣𝕪 𝔹𝕦𝕚𝕝𝕕 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
mandatory: $(MFA_BP_MANDATORY) library $(MFA_MANDATORY_HEADER) $(CLIENT) $(SERVER)

#⋆✴︎˚｡⋆✴︎˚｡⋆｡⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✴︎˚｡⋆⋆✿˚｡⋆⋆✴︎˚⋆✴⋆｡⋆⋆✴︎˚｡⋆✴︎
#        Main Building Commands            
#˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧₊˚♡˚₊‧⁺˖˖⁺‧
$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(INCS) -o $(CLIENT) $(CLIENT_SRC) $(ADD_LIB)

$(SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) $(INCS) -o $(SERVER) $(SERVER_SRC) $(ADD_LIB)

#  𝕄𝕪 𝕃𝕚𝕓𝕣𝕒𝕣𝕪 ℂ𝕠𝕞𝕞𝕒𝕟𝕕𝕤  #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
library: $(MFA_LIBRARY_HEADER)
	@make -C $(LIB_DIR) all --no-print-directory

library_clean:
	@make -C $(LIB_DIR) clean --no-print-directory

library_fclean:
	@make -C $(LIB_DIR) fclean --no-print-directory

# Color codes
# ────୨ৎ────
MYPINK = \033[38;2;255;105;180m
MYGREEN = \033[38;2;119;221;119m
MYYELLOW = \033[93m
MYRED = \033[31m
RESET = \033[0m

# Print
define pink_print
	@echo -e "$(MYPINK)$(1)$(RESET)"
endef

#  ℝ𝕖𝕞𝕠𝕧𝕖 𝔽𝕚𝕝𝕖𝕤  #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
clean: library_clean
	@if [ -d "(OBJ_DIR)" ]; then \
		echo "\n───$(MYPINK)୨ৎ$(RESET)──── $(MYPINK)Cleaning $(RESET) -» $(NAME) «- $(RESET)───$(MYPINK)୨ৎ$(RESET)────$(RESET)"; \
		$(RM) $(OBJ_DIR); \
		echo "$(MYGREEN)⋆ ˚｡⋆ $(RESET) -» $(NAME) «- $(RESET)objects removed $(MYGREEN)✔$(RESET)"; \
		else \
			echo "Nothing to be done for 'clean'."; \
			fi 

fclean: library_fclean
	@if [ -d "$(OBJ_DIR)" ] || [ -f "$(CLIENT)" ] || [ -f "$(SERVER)" ]; then \
 		echo "\n───$(MYPINK)୨ৎ$(RESET)──── $(MYPINK)Cleaning $(RESET) -» $(NAME) «- $(RESET)───$(MYPINK)୨ৎ$(RESET)────$(RESET)"; \
		if [ -d "$(OBJ_DIR)" ]; then \
			$(RM) $(OBJ_DIR); \
			echo "$(MYGREEN)⋆ ˚｡⋆ $(RESET) -» $(NAME) «- $(RESET)objects removed $(MYGREEN)✔$(RESET)"; \
		fi; \
		if [ -f "$(CLIENT)" ]; then \
			$(RM) $(CLIENT); \
			echo "$(MYGREEN)⋆ ˚｡⋆ $(RESET) -» $(CLIENT) «- $(RESET)file removed $(MYGREEN)✔$(RESET)"; \
		fi; \
		if [ -f "$(SERVER)" ]; then \
			$(RM) $(SERVER); \
			echo "$(MYGREEN)⋆ ˚｡⋆ $(RESET) -» $(SERVER) «- $(RESET)file removed $(MYGREEN)✔$(RESET)"; \
		fi; \
	else \
		echo "Nothing to be done for 'fclean'."; \
	fi

re: fclean all

# ℍ𝕖𝕒𝕕𝕖𝕣 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────
$(MFA_BP_MANDATORY):
	@mkdir -p $(OBJ_DIR)
	@echo "      ⠀⠀⠀⢠⡾⠲⠶⣤⣀⣠⣤⣤⣤$(MYRED)⡿⠛⠿$(RESET)⡴⠾⠛⢻⡆⠀⠀⠀"
	@echo "      ⠀⠀⠀⣼⠁⠀⠀⠀⠉⠁⠀$(MYRED)⢀⣿⠐⡿⣿⠿⣶⣤⣤⣷⡀⠀⠀$(RESET)"
	@echo "      ⠀⠀⠀⢹⡶⠀⠀⠀⠀⠀⠀$(MYRED)⠈⢯⣡⣿⣿⣀⣰⣿⣦⢂⡏⠀⠀$(RESET)"
	@echo "      ⠀⠀⢀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(MYRED)⠈⠉⠹⣍⣭⣾⠁⠀⠀$(RESET)"
	@echo "      ⠀⣀⣸⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣸⣧⣤⡀"
	@echo "      ⠈⠉⠹⣏⡁⠀⢸⣿⠀⠀⠀$(MYYELLOW)⢀⡀$(RESET)⠀⠀⠀⣿⠆⠀⢀⣸⣇⣀⠀"
	@echo "      ⠀⠐⠋⢻⣅⡄⢀⣀⣀⡀⠀$(MYYELLOW)⠯⠽⠂$(RESET)⢀⣀⣀⡀⠀⣤⣿⠀⠉⠀"
	@echo "      ⠀⠀⠴⠛⠙⣳⠋⠉⠉⠙⣆⠀⠀⢰⡟⠉⠈⠙⢷⠟⠈⠙⠂⠀"
	@echo "      ⠀⠀⠀⠀⠀⢻⣄⣠⣤⣴⠟⠛⠛⠛⢧⣤⣤⣀⡾⠀⠀⠀⠀⠀"
	@echo "   ╔──────────────────────────────────𐙚⋆°｡"
	@echo "   │,-,-,-.            ,--,--'  .  .  │"
	@echo "   │\`,| | |   . ,-. .  \`- | ,-. |  | ,│"
	@echo "   │  | ; | . | | | |   , | ,-| |  |< │"
	@echo "   │  '   \`-' ' ' ' '   \`-' \`-^ \`' ' \`│"
	@echo " °⋆𐙚──────────────────────────────────╝"
	@touch $(MFA_BP_MANDATORY) 

$(MFA_LIB_HEADER):
	@mkdir -p $(OBJ_DIR)
	@echo "\n───$(MYPINK)୨ৎ$(RESET)──── $(MYPINK)Generating $(RESET) -» Libft «- ───$(MYPINK)୨ৎ$(RESET)──── $(RESET)"
	@touch $(MFA_LIB_HEADER)

$(MFA_MANDATORY_HEADER):
	@mkdir -p $(OBJ_DIR)
	@echo "\n───$(MYPINK)୨ৎ$(RESET)──── $(MYPINK)Generating $(RESET) -» $(NAME) «- $(RESET) ───$(MYPINK)୨ৎ$(RESET)──── $(RESET)"
	@touch $(MFA_MANDATORY_HEADER)

# I may add the bonus part here someday 

# ℙ𝕙𝕠𝕟𝕪 ℝ𝕦𝕝𝕖𝕤 #
# ───୨ৎ──── ⑅ ♡ ⑅  ────୨ৎ────

.PHONY: clean fclean re all library 

#  ૮ ˶ᵔ ᵕ ᵔ˶ ა                               ✧₊⁺✧₊ ᓚᘏᗢ