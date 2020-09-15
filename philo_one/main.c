/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/15 17:34:08 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"


void		*time_test(void)
{
	struct timeval time_start;
	struct timeval time_now;
	gettimeofday(&time_start, NULL);
	printf("time [%d]", time_start.tv_usec);
	gettimeofday(&time_now, NULL);
	printf("\ntime now [%d]", time_now.tv_usec - time_start.tv_usec);
	return NULL;
}

void		*thread_philo(void *data)
{
	int i;
	int *id;

	i = 0 ;
	id = (int *)data;
	while (i < 3)
	{
		sleep(1);
		ft_printf("My Turn [%d]! ID[%d]\n", i, *id);
		i++;
	}
	return NULL;
}

void		create_thread(t_data_philo *data_philo)
{
	t_philo 		philo[data_philo->n_philo];
	unsigned int	i;

	i = 0;
	while (i < data_philo->n_philo)
	{
		pthread_create(&philo[i].thread, NULL, &thread_philo, &i);
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_data_philo		data_philo[0];

	if (management_data(ac, av, data_philo))
	{
		ft_printf("\nparsing error\n");
		return (1);
	}
	create_thread(data_philo);
	return (0);
}