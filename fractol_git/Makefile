# プロジェクトの設定
NAME = fractol
SRC = fractol.c calc_set.c mlx_utils.c utils.c render.c ft_func.c init.c hook.c
OBJS = $(SRC:%.c=%.o)

# MiniLibX のパス
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

# コンパイルフラグ
CFLAGS =  -O3 
LDFLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm 

# コンパイラ
CC = cc

# ビルドターゲット
all: $(MLX) $(NAME)

# bonus target
bonus: $(MLX) $(NAME)

$(MLX):
	@echo "Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $^ -o $(NAME) $(LDFLAGS)

# オブジェクトファイルの生成
%.o: %.c
	@echo "$(CC) $(CFLAGS) -c $< -o $@"
	$(CC) $(CFLAGS) -c $< -o $@

# クリーンアップターゲット
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

# テストターゲット
.PHONY: all clean fclean re