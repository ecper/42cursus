# コンパイラとフラグの設定
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ソースファイルとオブジェクトファイル
SRCS = ft_printf.c ft_putaddr_fd.c ft_putnbr_base_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_itoa.c
OBJS = $(SRCS:%.c=%.o)

# ライブラリ名とインクルードディレクトリ
NAME = libftprintf.a

LIB_DIR=libft
LIB_NAME=$(LIB_DIR)/libft.a

# デフォルトターゲット
all: $(NAME)

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)

# ライブラリの作成
$(NAME): $(OBJS) $(LIB_NAME)
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
	$(MAKE) -C $(LIB_DIR) clean
	
# フルクリーンアップ
fclean: clean
	@echo "rm -f $(NAME)"
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

# 再ビルド
re: fclean all
