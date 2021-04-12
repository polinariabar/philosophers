# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leweathe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 09:46:27 by leweathe          #+#    #+#              #
#    Updated: 2020/12/17 09:46:28 by leweathe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_one
FLAGS 	= -Wall -Wextra -Werror -pthread
HEADER 	= philo_one.h
SRCS	= main.c dinner.c help.c init.c monitoring.c utils/ft_atoi.c utils/ft_isdigit.c utils/ft_putnbr_fd.c utils/ft_putstr_fd.c utils/ft_strlen.c
OBJ		= $(SRCS:.c=.o)

%.o:%.c
	gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	gcc $(FLAGS) -lpthread -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

