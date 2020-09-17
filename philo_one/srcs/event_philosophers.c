/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:10:59 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/17 17:26:26 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_FORK);
	pthread_mutex_unlock(philo->display);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_FORK);
	pthread_mutex_unlock(philo->display);
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
}

void	philo_eat(t_philo *philo)
{
	struct timeval	last_meal;

	gettimeofday(&last_meal, NULL);
	pthread_mutex_lock(philo->display);
	philo->last_meal = last_meal.tv_usec;
	display_light(current_time(philo), philo->id, EVENT_EAT);
	pthread_mutex_unlock(philo->display);
	usleep(philo->data_philo->t_eat);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_SLEEP);
	pthread_mutex_unlock(philo->display);
	usleep(philo->data_philo->t_sleep);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_THINK);
	pthread_mutex_unlock(philo->display);
	usleep(1);
}
