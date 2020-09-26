/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:02:28 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/26 20:54:16 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_zero.h"

void		init_mutex_fork(t_philo *philo, int n_philo)
{
	int i;

	i = 0;
	while (i < n_philo)
	{
		philo[i].m_fork1 = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (philo[i].m_fork1 == NULL)
			return ;
		pthread_mutex_init(philo[i].m_fork1, NULL);
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		if (i == n_philo - 1)
			philo[i].m_fork2 = philo[0].m_fork1;
		else
			philo[i].m_fork2 = philo[i + 1].m_fork1;
		i++;
	}
}

void		init_mutex_display(t_philo *philo, int n_philo)
{
	int					i;
	pthread_mutex_t		*display;

	i = 0;
	if (!(display = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return ;
	pthread_mutex_init(display, NULL);
	while (i < n_philo)
	{
		philo[i].m_display = display;
		i++;
	}
}

void		init_philosopher(unsigned int n_philo, t_philo *philo)
{
	unsigned int i;

	i = 0;
	init_mutex_fork(philo, n_philo);
	init_mutex_display(philo, n_philo);
	while (i < n_philo)
	{
		philo[i].id = i + 1;
		philo[i].is_dead = 0;
		philo[i].last_meal = 0;
		i++;
	}
}
