# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 12:12:46 by ariane            #+#    #+#              #
#    Updated: 2022/03/25 15:12:20 by abonnel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Container

HEADER		=	srcs/metafunctions.hpp srcs/vector.hpp srcs/stack.hpp srcs/map.hpp srcs/iterator.hpp
SRCS		=	srcs/main.cpp
SRCSTEST	=	srcs/cleanmain.cpp

CC			=	clang++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
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
	rm -f $(OBJS) tester1 tester0

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re