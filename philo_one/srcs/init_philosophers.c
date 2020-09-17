/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:02:28 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/17 17:43:47 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

void		init_mutex_fork(t_philo *philo, int n_philo)
{
	int i;

	i = 0;
	while (i < n_philo)
	{
		philo[i].fork1 = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (philo[i].fork1 == NULL)
			return ;
		pthread_mutex_init(philo[i].fork1, NULL);
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		if (i == n_philo - 1)
			philo[i].fork2 = philo[0].fork1;
		else
			philo[i].fork2 = philo[i + 1].fork1;
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
		philo[i].display = display;
		i++;
	}
}

void		init_philo(t_data_philo *data_philo, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data_philo->n_philo)
	{
		init_mutex_fork(philo, data_philo->n_philo);
		init_mutex_display(philo, data_philo->n_philo);
		philo[i].data_philo = data_philo;
		philo[i].id = i;
		philo[i].is_dead = 0;
		philo[i].last_meal = 0;
		i++;
	}
}
