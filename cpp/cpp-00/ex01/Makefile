
CC=c++

FLAGS=-Wall -Wextra -Werror -std=c++98

NAME=hello

SRCS=Contact.cpp PhoneBook.cpp main.cpp

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