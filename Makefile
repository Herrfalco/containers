NAME	=	test
SRCS	=	main.cpp
OBJS	=	$(SRCS:.cpp=.opp)
CC		=	clang++-8 -std=c++98
CFLAGS	=	-fsanitize=address -fno-omit-frame-pointer -Wall -Wextra -Werror
RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

%.opp	:	%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
