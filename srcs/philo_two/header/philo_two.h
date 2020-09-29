/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:35:54 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/29 12:04:24 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHILO_TWO_H
# define __PHILO_TWO_H

# include "../../lib/header/philo.h"

# define MICROSEC	0
# define MILLESEC	1

# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct				s_philo
{
	pthread_t			thread;
	sem_t				*sem_forks;
	sem_t				*sem_display;
	unsigned int		id;
	unsigned int		is_dead;
	unsigned int		last_meal;
	t_bool				life;
}							t_philo;

void						init_philosopher(unsigned int n_philo, t_philo
							*philo);
void						philo_take_fork(t_stock *stock, t_philo *philo);
void						philo_eat(t_stock *s, t_philo *philo);
void						philo_sleep(t_stock *stock, t_philo *philo);
void						philo_think(t_stock *stock, t_philo *philo);
void						display_manager(t_stock *s, t_philo *philo,
							char *event);
void						display_all_meals_ate(t_data *data);
void						monitor(t_data *data, t_philo *philo);
void						*reaper(void *stock);

#endif
