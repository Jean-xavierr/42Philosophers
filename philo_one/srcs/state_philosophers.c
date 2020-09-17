/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:13:34 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/17 17:16:10 by jereligi         ###   ########.fr       */
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
