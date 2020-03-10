NAME	=	test
SRCS	=	tests/test_list.cpp \
			tests/test_vect.cpp \
			main.cpp
OBJS	=	$(SRCS:.cpp=.opp)
CC		=	clang++-8 -std=c++98
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer
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
