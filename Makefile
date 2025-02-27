SERVER_SOURCES = server.c
CLIENT_SOURCES = client.c
BONUS_SERVER_SOURCES = server_bonus.c
BONUS_CLIENT_SOURCES = client_bonus.c

SERVER_OBJECTS = server.o
CLIENT_OBJECTS = client.o
BONUS_SERVER_OBJECTS = server_bonus.o
BONUS_CLIENT_OBJECTS = client_bonus.o

SERVER = server
SERVER_BONUS = server_bonus
CLIENT = client
CLIENT_BONUS = client_bonus

CFLAGS = -Wall -Wextra -Werror
FT_PRINTF = ft_printf/ft_printf_utils.c ft_printf/ft_printf.c ft_printf/ft_putchar.c \
			ft_printf/ft_putnbr_base.c ft_printf/ft_putnbr.c ft_printf/ft_putptr.c ft_printf/ft_putstr.c \

CC = cc

all: $(SERVER) $(CLIENT) 

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $(FT_PRINTF) $(SERVER_OBJECTS) -o $(SERVER) 

$(CLIENT): $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $(FT_PRINTF) $(CLIENT_OBJECTS) -o $(CLIENT)

$(SERVER_BONUS): $(BONUS_SERVER_OBJECTS)
	$(CC) $(CFLAGS) $(FT_PRINTF) $(BONUS_SERVER_OBJECTS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(BONUS_CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $(FT_PRINTF) $(BONUS_CLIENT_OBJECTS) -o $(CLIENT_BONUS)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(SERVER_OBJECTS) $(CLIENT_OBJECTS) $(BONUS_SERVER_OBJECTS) $(BONUS_CLIENT_OBJECTS)

fclean: clean
	rm -rf $(SERVER) $(SERVER_BONUS)
	rm -rf $(CLIENT) $(CLIENT_BONUS)

re: fclean all
