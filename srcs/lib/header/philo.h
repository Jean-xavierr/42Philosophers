/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:27:31 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/28 15:22:31 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

# define EVENT_FORK		"has taken a fork"
# define EVENT_EAT		"is eating"
# define EVENT_SLEEP	"is sleeping"
# define EVENT_THINK	"is thinking"
# define EVENT_DEAD		"is dead"

# define ONE_MILLISEC 	1000

# define TRUE			1
# define FALSE			0

typedef char				t_bool;

typedef struct				s_data
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	nb_meals;
	unsigned int	meals_finish;
	unsigned int	t_start_usec;
	unsigned int	t_start_sec;
	t_bool			meals;
	t_bool			option;
	t_bool			one_die;
}							t_data;

typedef	struct				s_stock
{
	struct s_data	*data;
	struct s_philo	*philo;
}							t_stock;

/*
** Function for all Philo
*/
void						print_usage(void);
void						print_error_more_arg(void);
int							parsing_manager(t_data *data);
void						print_error_not_enought_arg(void);
int							data_manager(int ac, char **av, t_data *data);
int							check_argument(int ac, char **av, int *prog_arg);
unsigned int				get_time_start(int time);
unsigned int				get_time(unsigned int start_usec,
							unsigned int start_sec);
char						**uitoemoji(unsigned int nb);

/*
** ft_function
*/
int							ft_strlen(char *s);
char						*ft_strdup(char *s1);
int							len_nb(unsigned int nb);
char						*ft_utoa(unsigned int n);
char						*ft_strtabtostr(char **s);
int							ft_atoi(char *str, int *i);
int							ft_strcmp(char *s1, char *s2);
char						*ft_strjoindel(char *s1, char *s2, int param);
void						*ft_memcpy_n(void *dst, void *src, unsigned int n);

#endif
