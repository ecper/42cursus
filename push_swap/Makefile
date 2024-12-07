SOURCES = ft_atoi.c ft_contentdelone.c ft_isdigit.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
		push_swap.c push.c rotate.c rrotate.c swap.c compression.c validator.c utils.c ft_split.c \
		ft_strlen.c ft_substr.c ft_strdup.c ft_strlcpy.c sort.c exit_utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

# 実行ファイル名
NAME = push_swap

# 通常ビルド（all）
all: $(NAME) 

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
