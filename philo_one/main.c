/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/16 17:27:53 by jereligi         ###   ########.fr       */
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
	t_philo 	*philo;

	i = 0;
	philo = (t_philo *)data;
	while (i < 5)
	{
		sleep(2);
		pthread_mutex_lock(philo->display);
		ft_printf("id[%d] sleep 2 sec\n",philo->id);
		usleep(60);
		pthread_mutex_unlock(philo->display);
		pthread_mutex_lock(philo->fork1);
		pthread_mutex_lock(philo->fork2);
		sleep(3);
		pthread_mutex_lock(philo->display);
		ft_printf("id[%d] eat 3 sec\n",philo->id);
		pthread_mutex_unlock(philo->display);
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		i++;
	}
	return NULL;
}

void		init_mutex_fork(t_philo *philo, int n_philo)
{
	int i;

	i = 0;
	while (i < n_philo)
	{
		if (!(philo[i].fork1= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
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
	int 				i;
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

void		create_thread(t_data_philo *data_philo)
{
	t_philo 		philo[data_philo->n_philo];
	unsigned int	i;

	i = 0;
	while (i < data_philo->n_philo)
	{
		init_mutex_fork(philo, data_philo->n_philo);
		init_mutex_display(philo, data_philo->n_philo);
		philo[i].id = i;
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
	t_data_philo		data_philo[0];

	if (management_data(ac, av, data_philo))
	{
		ft_printf("\nparsing error\n");
		return (1);
	}
	create_thread(data_philo);
	return (0);
}