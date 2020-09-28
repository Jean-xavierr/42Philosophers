/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:00:09 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/28 11:45:01 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_zero.h"

void		kill_philosophers(t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philo)
		pthread_detach(philo[i++].thread);
}

void		monitor_die(t_data *data, t_philo *philo)
{
	while (!data->one_die)
		usleep(ONE_MILLISEC);
	if (data->one_die)
		kill_philosophers(data, philo);
}

void		monitor_meals(t_data *data, t_philo *philo)
{
	unsigned int	time;

	time = 0;
	while (!data->one_die && (data->meals_finish < data->n_philo))
		usleep(ONE_MILLISEC);
	if (data->one_die == 1 || (data->meals_finish == data->n_philo))
		kill_philosophers(data, philo);
	if (data->option && data->meals_finish == data->n_philo)
	{
		pthread_mutex_lock(philo->m_display);
		display_all_meals_ate(data);
	}
	else if (!data->option && data->meals_finish == data->n_philo)
	{
		pthread_mutex_lock(philo->m_display);
		time = get_time(data->t_start_usec, data->t_start_sec);
		display_light_all_meals_ate(data, philo, time);
	}
}

void		monitor(t_data *data, t_philo *philo)
{
	if (data->meals)
		monitor_meals(data, philo);
	else
		monitor_die(data, philo);
}
