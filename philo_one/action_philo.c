/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:10:59 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/17 16:08:53 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		current_time(t_philo *philo)
{
	struct timeval	time_now;
	unsigned int	current_time;

	gettimeofday(&time_now, NULL);
	philo->time_action = time_now.tv_usec;
	current_time = philo->time_action - philo->data_philo[0].time_start;
	return (current_time);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_FORK);
	pthread_mutex_unlock(philo->display);
	pthread_mutex_lock(philo->fork2);
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_FORK);
	pthread_mutex_unlock(philo->display);
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_EAT);
	pthread_mutex_unlock(philo->display);
	usleep(philo->data_philo->t_eat);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_EAT);
	pthread_mutex_unlock(philo->display);
	usleep(philo->data_philo->t_sleep);
	pthread_mutex_lock(philo->display);
	display_light(current_time(philo), philo->id, EVENT_THINK);
	pthread_mutex_unlock(philo->display);
	usleep(1);
}


