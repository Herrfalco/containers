NAME	=	test
SRCS	=	Test/test_list.cpp \
			Test/test_vector.cpp \
			Test/test_map.cpp \
			Test/test_deque.cpp \
			Test/test_stack.cpp \
			Test/test_queue.cpp \
			Test/test_set.cpp \
			Test/test_multiset.cpp \
			Test/test_multimap.cpp \
			main.cpp
OBJS	=	$(SRCS:.cpp=.opp)
CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

%.opp	:	%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJS) .tmp

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
