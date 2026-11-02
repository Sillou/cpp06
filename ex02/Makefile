# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 16:27:45 by alubrano          #+#    #+#              #
#    Updated: 2026/11/02 16:27:46 by alubrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= identify

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp Base.cpp Functions.cpp
OBJS		= $(SRCS:.cpp=.o)
HEADERS		= Base.hpp A.hpp B.hpp C.hpp Functions.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
