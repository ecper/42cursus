# コンパイラとフラグの設定
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ソースファイルとオブジェクトファイル
SRCS = ft_striteri.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = $(SRCS:%.c=%.o)

# ライブラリ名とインクルードディレクトリ
LIB_NAME = libft.a

# デフォルトターゲット
all: $(LIB_NAME)

# ライブラリの作成
$(LIB_NAME): $(OBJS)
	@echo "ar rcs $@ $^"
	ar rcs $@ $^

# オブジェクトファイルの生成
%.o: %.c
	@echo "$(CC) $(CFLAGS) -c $< -o $@"
	$(CC) $(CFLAGS) -c $< -o $@

# クリーンアップ
clean:
	@echo "rm -f $(OBJS)"
	rm -f $(OBJS)

# フルクリーンアップ
fclean: clean
	@echo "rm -f $(LIB_NAME)"
	rm -f $(LIB_NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

# 再ビルド
re: fclean all
