# コンパイラとフラグの設定
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# 通常のソースコードとオブジェクトファイル
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

# ボーナス用のソースコードとオブジェクトファイル
BONUS_SOURCES = server_bonus.c client_bonus.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

# 実行ファイル名
NAME = server
CLIENT_NAME = client

# ボーナス用の実行ファイル名（通常のファイル名にリンク）
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

# ライブラリ
LIBFT_NAME = libft/libft.a
FT_PRINTF_NAME = ft_printf/libftprintf.a

# 通常ビルド（all）
all: $(NAME) $(CLIENT_NAME)

bonus: $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

$(NAME): server.o $(FT_PRINTF_NAME) $(LIBFT_NAME)
	$(CC) -o $@ $^ $(FT_PRINTF_NAME) $(LIBFT_NAME)

$(CLIENT_NAME): client.o $(FT_PRINTF_NAME) $(LIBFT_NAME)
	$(CC) -o $@ $^ $(FT_PRINTF_NAME) $(LIBFT_NAME)

$(SERVER_BONUS_NAME): server_bonus.o $(FT_PRINTF_NAME) $(LIBFT_NAME)
	$(CC) -o $(SERVER_BONUS_NAME) server_bonus.o $(FT_PRINTF_NAME) $(LIBFT_NAME)

$(CLIENT_BONUS_NAME): client_bonus.o $(FT_PRINTF_NAME) $(LIBFT_NAME)
	$(CC) -o $(CLIENT_BONUS_NAME) client_bonus.o $(FT_PRINTF_NAME) $(LIBFT_NAME)

$(LIBFT_NAME):
	$(MAKE) -C libft

$(FT_PRINTF_NAME):
	$(MAKE) -C ft_printf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

# server.o: server.c
# 	$(CC) -c $(CFLAGS) server.c

# client.o: client.c
# 	$(CC) -c $(CFLAGS) client.c

# server_bonus.o: server_bonus.c
# 	$(CC) -c $(CFLAGS) server_bonus.c

# client_bonus.o: client_bonus.c
# 	$(CC) -c $(CFLAGS) client_bonus.c

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	make -C libft clean
	make -C ft_printf clean
	
fclean: clean
	rm -f $(NAME) $(CLIENT_NAME) $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)
	rm -f $(LIBFT_NAME) $(FT_PRINTF_NAME)

# 再ビルド（fclean -> all）
re: fclean all
