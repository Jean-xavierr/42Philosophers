# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 17:53:32 by jereligi          #+#    #+#              #
#    Updated: 2020/09/24 17:56:24 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

SRCS_PHILO_TWO = 	srcs/reaper.c 				\
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

SRCS_PRINTF = 		../lib/ft_printf/srcs/ft_itoa.c						\
					../lib/ft_printf/srcs/ft_itox.c						\
					../lib/ft_printf/srcs/ft_ultox.c					\
					../lib/ft_printf/srcs/ft_utils.c					\
					../lib/ft_printf/srcs/ft_printf.c					\
					../lib/ft_printf/srcs/ft_check_set.c				\
					../lib/ft_printf/srcs/ft_get_strlen.c				\
					../lib/ft_printf/srcs/ft_check_flags.c				\
					../lib/ft_printf/srcs/ft_strjoin_char.c				\
					../lib/ft_printf/srcs/ft_unsigned_itoa.c			\
					../lib/ft_printf/srcs/ft_exception_flag.c			\
					../lib/ft_printf/srcs/ft_flags_management.c			\
					../lib/ft_printf/srcs/ft_display_management.c		\
					../lib/ft_printf/srcs/ft_flags_management_integer.c	\

OBJ = $(_SRCS_PHILO_TWO:.c=.o)

OBJ_FT_FUNCTION = $(_SRCS_FT_FUCTION:.c=.o)

OBJ_PHILO = $(_SRCS_PHILO:.c=.o)

OBJ_PRINTF = $(_SRCS_PRINTF:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :	
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS_PHILO_TWO) $(SRCS_FT_FUCTION) $(SRCS_PHILO) $(SRCS_PRINTF)

clean : 
			rm -rf $(OBJ) $(OBJ_FT_FUNCTION) $(OBJ_PHILO) $(OBJ_PRINTF)

fclean :	clean
			rm -rf $(NAME)

re : fclean all