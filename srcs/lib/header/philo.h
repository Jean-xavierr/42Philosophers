/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:27:31 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/18 16:04:08 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
# define EVENT_DIE		"is died"

# define TRUE				1
# define FALSE				0

typedef char				t_bool;
typedef	pthread_t			t_thread;
typedef	pthread_mutex_t		t_mutex;	

typedef struct				s_data
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	nb_meals;
	unsigned int	time_start;
	t_bool			meals;
	t_bool			option;
	t_bool			one_die;
}							t_data;

/*
** Function for all Philo
*/
void						print_usage(void);
void						print_error_more_arg(void);
int							parsing_manager(t_data *data);
void						print_error_not_enought_arg(int nb);
int							data_manager(int ac, char **av, t_data *data);
int							check_argument(int ac, char **av, int *prog_arg);

/*
** Utils
*/
void						ft_putstr(char *s);
int							ft_strlen(char *s);
char						*ft_utoa(unsigned int n);
int							ft_atoi(char *str, int *i);
int							ft_strncmp(char *s1, char *s2);

#endif
