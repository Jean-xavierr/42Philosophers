/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:08:00 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/29 12:00:54 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "../../lib/header/philo.h"

# define MICROSEC	0
# define MILLESEC	1

typedef struct				s_philo
{
	pthread_t			thread;
	pthread_mutex_t		*m_fork1;
	pthread_mutex_t		*m_fork2;
	pthread_mutex_t		*m_display;
	unsigned int		id;
	unsigned int		is_dead;
	unsigned int		last_meal;
	t_bool				life;
}							t_philo;

/*
** init_philo.c
*/
void						init_philosopher(unsigned int n_philo,
							t_philo *philo);
void						philo_take_fork(t_stock *stock, t_philo *philo);
void						philo_eat(t_stock *stock, t_philo *philo);
void						philo_sleep(t_stock *stock, t_philo *philo);
void						philo_think(t_stock *stock, t_philo *philo);
void						display_manager(t_stock *stock, t_philo *philo,
							char *event);
void						*reaper(void *stock);
void						monitor(t_data *data, t_philo *philo);
void						display_all_meals_ate(t_data *data);
void						display_manager(t_stock *s, t_philo *philo,
							char *event);

#endif
