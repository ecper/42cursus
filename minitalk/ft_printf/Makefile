# コンパイラとフラグの設定
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ソースファイルとオブジェクトファイル
SRCS = ft_printf.c ft_putaddr_fd.c ft_putnbr_base_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_itoa.c
OBJS = $(SRCS:%.c=%.o)

NAME = libftprintf.a

all: $(NAME)

# ライブラリの作成
$(NAME): $(OBJS)
	@echo "ar rcs $@ $^"
	ar rcs $@ $^

# オブジェクトファイルの生成
%.o: %.c
	@echo "$(CC) $(CFLAGS)  -c $< -o $@"
	$(CC) $(CFLAGS)  -c $< -o $@

# クリーンアップ
clean:
	@echo "rm -f $(OBJS)"
	rm -f $(OBJS)

# フルクリーンアップ
fclean: clean
	@echo "rm -f $(NAME)"
	rm -f $(NAME)

# 再ビルド
re: fclean all
