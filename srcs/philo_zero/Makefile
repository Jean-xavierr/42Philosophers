# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 17:12:34 by jereligi          #+#    #+#              #
#    Updated: 2020/09/28 16:44:46 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -pthread
endif

NAME = philo_zero

SRCS_PHILO_ZERO = 	srcs/reaper.c 				\
					srcs/monitor.c				\
					srcs/philosophers.c			\
					srcs/display_emoji.c		\
					srcs/display_light.c		\
					srcs/init_philosophers.c	\
					srcs/philosophers_action.c	\
					srcs/parsing.c				\
					srcs/print_usage.c			\

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

SRCS_PHILO =		../lib/srcs_philosophers/get_time.c			\
					../lib/srcs_philosophers/data_manager.c		\
					../lib/srcs_philosophers/check_argument.c 	\

SRCS_PRINTF = 		ft_printf/srcs/ft_itoa.c					\
					ft_printf/srcs/ft_itox.c					\
					ft_printf/srcs/ft_ultox.c					\
					ft_printf/srcs/ft_utils.c					\
					ft_printf/srcs/ft_printf.c					\
					ft_printf/srcs/ft_check_set.c				\
					ft_printf/srcs/ft_get_strlen.c				\
					ft_printf/srcs/ft_check_flags.c				\
					ft_printf/srcs/ft_strjoin_char.c			\
					ft_printf/srcs/ft_unsigned_itoa.c			\
					ft_printf/srcs/ft_exception_flag.c			\
					ft_printf/srcs/ft_flags_management.c		\
					ft_printf/srcs/ft_display_management.c		\
					ft_printf/srcs/ft_flags_management_integer.c\

OBJ = $(SRCS_PHILO_ZERO:.c=.o)

OBJ_FT_FUNCTION = $(SRCS_FT_FUCTION:.c=.o)

OBJ_PHILO = $(SRCS_PHILO:.c=.o)

OBJ_PRINTF = $(SRCS_PRINTF:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :	$(OBJ) $(OBJ_FT_FUNCTION) $(OBJ_PHILO) $(OBJ_PRINTF)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_FT_FUNCTION) $(OBJ_PHILO) $(OBJ_PRINTF)

clean : 
			rm -rf $(OBJ) $(OBJ_FT_FUNCTION) $(OBJ_PHILO) $(OBJ_PRINTF)

fclean :	clean
			rm -rf $(NAME)

re : fclean all