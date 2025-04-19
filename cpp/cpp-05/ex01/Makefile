
CCX=c++

CCX_FLAGS=-Wall -Wextra -Werror -std=c++98

NAME=a.out

SRCS=Bureaucrat.cpp Form.cpp main.cpp

OBJS=$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CCX) -o $@ $^

$(OBJS): $(SRCS)
	$(CCX) $(CCX_FLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean $(NAME)