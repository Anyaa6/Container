# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 12:12:46 by ariane            #+#    #+#              #
#    Updated: 2022/04/26 12:33:17 by abonnel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Container

HEADER		=	srcs/utils/metafunctions.hpp srcs/utils/pair.hpp \
				srcs/utils/node.hpp srcs/utils/lexicographical_compare.hpp \
				srcs/containers/vector.hpp srcs/containers/stack.hpp \
				srcs/containers/map.hpp \
				srcs/iterators/iterator.hpp srcs/iterators/random_access_iterator.hpp \
				srcs/iterators/reverse_iterator.hpp srcs/iterators/bidirectional_iterator.hpp
				
				
SRCS		=	srcs/tests/main.cpp
SRCSTEST	=	srcs/tests/cleanmain.cpp
STDTEST		=	srcs/tests/map_tests.cpp

OBJS		=	$(SRCS:.cpp=.o) 
OBJSTEST	=	$(SRCSTEST:.cpp=.o)
OBJS_STD	=	$(STDTEST:.cpp=.o)

CC			=	clang++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98 $(DFLAGS)
#-g3 -fsanitize=address

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		
all:	$(NAME)

tester:	$(OBJSTEST) $(HEADER)
	$(CC) $(CFLAGS) $(OBJSTEST) -o $(NAME)

std:	$(OBJS_STD) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS_STD) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSTEST)

fclean:	clean
	rm -f $(NAME)

tclean :
	rm -f output_ft output_std

re:		fclean all

.PHONY: all clean fclean re tclean