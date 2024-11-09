NAME = libft.a

# Compiler
CC = cc

# Flags
CFLAGS = -Wall -Wextra -Werror

# Sources
SRCS = \
    ft_atoi.c \
    ft_bzero.c \
    ft_calloc.c \
    ft_isalpha.c \
    ft_isalnum.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c \
    ft_strdup.c \
    ft_strlen.c \
    ft_strchr.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strnstr.c \
    ft_strncmp.c \
    ft_strtrim.c \
    ft_split.c \
    ft_substr.c \
    ft_tolower.c \
    ft_toupper.c \
	ft_strrchr.c \
	ft_itoa.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

# Convert files to objects files
OBJS = $(SRCS:.c=.o)

#Compile every file .c in .o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Compile Static Library
${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

# Principal Rule
all: ${NAME}

# Clean object files
clean:
	rm -f ${OBJS}

# Clean completely (obj and library)
fclean: clean
	rm -f ${NAME}
	rm libft.so

# Recompile
re: fclean all 

# Tester
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)
