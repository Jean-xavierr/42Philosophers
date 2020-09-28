# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 22:00:15 by Jeanxavier        #+#    #+#              #
#    Updated: 2020/09/28 16:44:15 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -pthread
endif

NAME = philo_one

SRCS_PHILO_ONE = 	srcs/reaper.c 				\
					srcs/display.c				\
					srcs/monitor.c				\
					srcs/philosophers.c			\
					srcs/init_philosophers.c	\
					srcs/philosophers_action.c	\

SRCS_FT_FUCTION =	../lib/ft_function/ft_atoi.c		\
					../lib/ft_function/ft_utoa.c		\
					../lib/ft_function/ft_len_nb.c		\
					../lib/ft_function/uitoemoji.c		\
					../lib/ft_function/ft_strcmp.c		\
					../lib/ft_function/ft_strdup.c		\
					../lib/ft_function/ft_strlen.c		\
					../lib/ft_function/ft_strjoin.c		\
					../lib/ft_function/ft_memcpy_n.c	\
					../lib/ft_function/ft_strjoindel.c	\
					../lib/ft_function/ft_strtabtostr.c	\

SRCS_PHILO =		../lib/srcs_philosophers/parsing.c			\
					../lib/srcs_philosophers/get_time.c			\
					../lib/srcs_philosophers/print_usage.c		\
					../lib/srcs_philosophers/data_manager.c		\
					../lib/srcs_philosophers/check_argument.c 	\

OBJ = $(SRCS_PHILO_ONE:.c=.o)

OBJ_FT_FUNCTION = $(SRCS_FT_FUCTION:.c=.o)

OBJ_PHILO = $(SRCS_PHILO:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :	$(OBJ) $(OBJ_FT_FUNCTION) $(OBJ_PHILO)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_FT_FUNCTION) $(OBJ_PHILO)
clean : 
			rm -rf $(OBJ) $(OBJ_FT_FUNCTION) $(OBJ_PHILO)

fclean :	clean
			rm -rf $(NAME)

re : fclean all