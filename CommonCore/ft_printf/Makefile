#⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°☆⋆⋆｡𖦹°‧☆#
#                                                #
#                                                #
#           𐙚 𝓜𝓪𝓴𝓮𝓯𝓲𝓵𝓮 𝓟𝓻𝓲𝓷𝓽𝓯 𝓛𝓲𝓫𝓻𝓪𝓻𝔂. 𐙚             #
#                                                #
#                                                #
#☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧☆⋆｡𖦹°‧⋆｡𖦹°‧☆#

SRCS = src/printch.c \
src/printst.c \
src/printpo.c \
src/printdi.c \
src/printun.c \
src/printhe.c \
src/printhm.c \
printf/ft_printf.c

OBJS	= ${SRCS:.c=.o}
INCS	= include
NAME	= libftprintf.a
LIBC	= ar crs
CC	= cc 
RM	= rm -f 
CFLAGS	= -Wall -Wextra -Werror

.c.o: 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	cp libft/libft.a ${NAME}
	ar crs ${NAME} ${OBJS} libft/libft.a

all: ${NAME}

clean: 
	${MAKE} clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
