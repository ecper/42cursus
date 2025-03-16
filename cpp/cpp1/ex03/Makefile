CC=c++

FLAGS=-Wall -Wextra -Werror -std=c++98 -g

NAME=Weapon

SRCS=HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

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