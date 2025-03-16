CC=c++

FLAGS=-Wall -Wextra -Werror -std=c++98 -g

NAME=HI_THIS_IS_BRAIN

SRCS=main.cpp

OBJS=$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean $(NAME)