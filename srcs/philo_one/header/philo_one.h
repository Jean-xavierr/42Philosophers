/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:08:00 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/18 16:06:19 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHILO_ONE_H
# define __PHILO_ONE_H

# include "../../lib/header/philo.h"

typedef	struct 				s_stock
{
	t_data			data;
	t_philo			philo;
}							t_stock;

typedef struct				s_philo
{
	pthread_t			thread;
	pthread_mutex_t		*m_fork1;
	pthread_mutex_t		*m_fork2;
	pthread_mutex_t		*m_display;
	unsigned int		id;
	unsigned int		last_meal;
	unsigned int		is_dead;
}							t_philo;

/*
** init_philo.c
*/
void						init_philo(t_data *data, t_philo *philo);

#endif
