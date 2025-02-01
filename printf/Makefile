SRC = ft_printf_utils.c ft_printf.c ft_putchar.c \
	ft_putnbr_base.c ft_putnbr.c ft_putptr.c ft_putstr.c

NAME = libftprintf.a
OBJ = ${SRC:.c=.o}
CC = cc
CF = -Wall -Wextra -Werror
AR = ar rcs

all : ${NAME}

${NAME} : ${OBJ}
	${AR} ${NAME} ${OBJ}

%.o : %.c ft_printf.h
	${CC} ${CF} -c $< -o $@

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean all