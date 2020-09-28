/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:16:46 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/28 14:56:37 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_two.h"

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
	while (!data->one_die && (data->meals_finish < data->n_philo))
		usleep(ONE_MILLISEC);
	if (data->one_die == 1 || (data->meals_finish == data->n_philo))
		kill_philosophers(data, philo);
	if (!data->one_die && data->meals_finish == data->n_philo)
	{
		sem_wait(philo->sem_display);
		display_all_meals_ate(data);
	}
}

void		monitor(t_data *data, t_philo *philo)
{
	if (data->meals)
		monitor_meals(data, philo);
	else
		monitor_die(data, philo);
}
