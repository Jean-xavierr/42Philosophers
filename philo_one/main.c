/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/17 15:37:57 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*thread_philo(void *data)
{
	int i;
	t_philo		*philo;

	i = 0;
	philo = (t_philo *)data;
	while (i < 2)
	{
		philo_eat(philo);
		i++;
	}
	return NULL;
}

void		launch_philo(t_data_philo *data_philo)
{
	t_philo 		*philo;
	struct timeval	time_start;
	unsigned int	i;

	if (!(philo = (t_philo*)malloc(sizeof(t_philo) * data_philo->n_philo)))
		return ;	
	i = 0;
	init_philo(data_philo, philo);
	gettimeofday(&time_start, NULL);
	data_philo[0].time_start = time_start.tv_usec;
	while (i < data_philo->n_philo)
	{
		pthread_create(&philo[i].thread, NULL, &thread_philo, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data_philo->n_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_data_philo		*data_philo;

	if (!(data_philo = (t_data_philo*)malloc(sizeof(t_data_philo))))
		return (0);
	if (management_data(ac, av, data_philo))
		return (1);
	launch_philo(data_philo);
	return (0);
}