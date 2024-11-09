.DEFAULT_GOAL	:= a
UTILS			= $(addprefix utils/, sigsegv.cpp color.cpp check.cpp leaks.cpp)
PARENT_DIR		= $(shell dirname $(shell pwd))
LIBFT_PATH		= $(PARENT_DIR)
TESTS_PATH		= tests/
MANDATORY		= memset bzero memcpy memmove memchr memcmp strlen isalpha isdigit isalnum \
				isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
				atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
				putendl_fd putnbr_fd striteri
BONUS			= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
VSOPEN			= $(addprefix vs, $(MANDATORY)) $(addprefix vs, $(BONUS))

COLOR_RESET = \033[0m
COLOR_RED = \033[31m
COLOR_GREEN = \033[32m
COLOR_YELLOW = \033[33m
COLOR_BLUE = \033[34m
COLOR_MAGENTA = \033[35m
COLOR_CYAN = \033[36m
COLOR_WHITE = \033[37m


CC		= clang++
CFLAGS	= -g3 -ldl -gdwarf-4 -std=c++11 -I utils/ -I$(LIBFT_PATH) 
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	VALGRIND = valgrind -q --leak-check=full
endif
ifeq ($(IN_DOCKER),TRUE)
	LIBFT_PATH = /project/
endif

# Object files and library for utils
UTILS_OBJS = $(UTILS:.cpp=.o)
UTILS_LIB  = utils/libutils.a

# Compile the utils as a static library
$(UTILS_LIB): $(UTILS_OBJS)
	@ar rcs $@ $^

# Rule to compile .cpp files into .o files
%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to run tests for functions
define RUN_TEST
	@$(CC) $(CFLAGS) $(TESTS_PATH)ft_$*_test.cpp $(UTILS_LIB) -L$(LIBFT_PATH) -lft && $(VALGRIND) ./a.out && rm -f a.out
endef

$(MANDATORY): %: $(UTILS_LIB)
	$(RUN_TEST)

$(BONUS): %: $(UTILS_LIB)
	$(RUN_TEST)

$(VSOPEN): vs%:
	@code $(TESTS_PATH)ft_$*_test.cpp

mandatory_start:
	@tput setaf 6
	@make -C $(LIBFT_PATH) > /dev/null
	@tput setaf 4 && echo [Mandatory]

bonus_start:
	@tput setaf 6
	@make bonus -C $(LIBFT_PATH) > /dev/null
	@tput setaf 5 && echo [Bonus]

checkmakefile:
	@ls $(LIBFT_PATH) | grep Makefile > /dev/null 2>&1 || (tput setaf 1 && echo Makefile not found. && exit 1)

$(addprefix docker, $(MANDATORY)) $(addprefix docker, $(BONUS)) dockerm dockerb dockera: docker%:
	@docker rm -f mc > /dev/null 2>&1 || true
	docker build -qt mi .
	docker run -e IN_DOCKER=TRUE -dti --name mc -v $(LIBFT_PATH):/project/ -v $(PARENT_DIR)/libftTester:/project/libftTester mi
	docker exec -ti mc make $* -C libftTester || true
	@docker rm -f mc > /dev/null 2>&1

m: mandatory_start $(MANDATORY)
b: bonus_start $(BONUS)
a: m b 

re: fclean a
clean:
	@make clean -C $(LIBFT_PATH) && rm -rf a.out* $(UTILS_OBJS) $(UTILS_LIB)

fclean:
	@make fclean -C $(LIBFT_PATH) && rm -rf a.out* $(UTILS_OBJS) $(UTILS_LIB)

.PHONY:	mandatory_start m bonus_start b a fclean clean re$(VSOPEN)
