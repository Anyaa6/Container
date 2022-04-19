# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 12:12:46 by ariane            #+#    #+#              #
#    Updated: 2022/04/04 14:27:43 by abonnel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Container

HEADER		=	srcs/metafunctions.hpp srcs/vector.hpp srcs/stack.hpp \
				srcs/map.hpp srcs/iterator.hpp srcs/pair.hpp
				
SRCS		=	srcs/main.cpp

SRCSTEST	=	srcs/tests/cleanmain.cpp

CC			=	clang++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98 $(DFLAGS)
#-g3 -fsanitize=address

OBJS		=	$(SRCS:.cpp=.o) 
OBJSTEST	=	$(SRCSTEST:.cpp=.o)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		
all:	$(NAME)

tester:	$(OBJSTEST) $(HEADER)
	$(CC) $(CFLAGS) $(OBJSTEST) -o $(NAME)

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