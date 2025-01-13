SERVER = server.c ft_printf/*.c

CLIENT = client.c ft_printf/*.c

BONUS_SERVER = server_bonus.c ft_printf/*.c

BONUS_CLIENT = client_bonus.c ft_printf/*.c

CFLAGS = -Wall -Wextra -Werror

all : minitalk.h
	cc ${SERVER} -o server
	cc ${CLIENT} -o client

bonus : minitalk_bonus.h
	cc ${BONUS_SERVER} -o server_bonus
	cc ${BONUS_CLIENT} -o client_bonus

clean :
	rm rf *.o

fclean : clean
	rm -rf server
	rm -rf client

re : fclean all