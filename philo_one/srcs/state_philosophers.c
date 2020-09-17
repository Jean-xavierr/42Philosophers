/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:13:34 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/17 17:50:40 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

int		current_time(t_philo *philo)
{
	struct timeval	time_now;
	unsigned int	current_time;

	gettimeofday(&time_now, NULL);
	philo->time_action = time_now.tv_usec;
	current_time = philo->time_action - philo->data_philo[0].time_start;
	return (current_time);
}

void	philo_is_dead(t_philo *philo)
{
	int				is_dead;
	struct timeval	current_t;

	gettimeofday(&current_t, NULL);
	if (philo->last_meal == 0)
		is_dead = current_t.tv_usec - philo->data_philo->time_start;
	else
		is_dead = current_t.tv_usec - philo->last_meal;
	if (is_dead > philo->data_philo->t_die)
	{
		philo->is_dead = 1;
		pthread_mutex_lock(philo->display);
		display_light(current_time(philo), philo->id, EVENT_DIE);
		pthread_mutex_unlock(philo->display);
	}
}