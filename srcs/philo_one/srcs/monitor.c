/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:00:09 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/23 10:57:58 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

void		kill_philosophers(t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	printf("COUCOU\n");
	while (i < data->n_philo)
	{
		printf("\ntest\n");
		pthread_detach(philo[i].thread);
		i++;
	}
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
	if (data->option)
		display_all_meals_ate(data);
}

void		monitor(t_data *data, t_philo *philo)
{
	if (data->meals)
		monitor_meals(data, philo);
	else
		monitor_die(data, philo);
}
