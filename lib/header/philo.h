/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:27:31 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/16 16:36:08 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN    "\x1b[36m"
# define COLOR_RESET   "\x1b[0m"

typedef struct				s_data_philo
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	meals;
	unsigned int	nb_meals;
}							t_data_philo;

/*
** Function Global
*/

int							ft_strlen(char *s);
char						*ft_strdup(char *s1);
char						*ft_strjoin(char *s1, char *s2);
char						**uitoemoji(int nb);
char						*ft_strjoindel(char *s1, char *s2, int param);
void						*ft_memcpy_n(void *dst, void *src, unsigned int n);
int							ft_strncmp(char *s1, char *s2);
int							ft_atoi(char *str, int *i);

/*
** Function for all Philo
*/

int							check_argument(int ac, char **av, int *prog_arg);
void						print_clasic_display(char *time, int id_philo,
							int event);
void						print_event(char *time, char **id_philo, int event);
void						print_usage(void);
void						start_display(void);
void						print_error_not_enought_arg(int nb);
void						print_error_more_arg(void);
int							parsing_nb_philo(int nb);
int							parsing_time_to(int time_to, char *s);
int							parsing_number_of_meals(int nb_meals);
int							management_data(int ac, char **av,
							t_data_philo *data_philo);
int							managmenent_parsing(t_data_philo *data_philo);

#endif
