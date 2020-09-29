/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:01:38 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/29 14:36:59 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_three.h"

void		life_philosophers(t_stock *s, t_philo *philo)
{
	unsigned int	i;
	t_data			*data;
	pthread_t		death;

	i = 0;
	data = s->data;
	while (!data->one_die && (!data->meals || i < data->nb_meals))
	{
		pthread_detach(death);
		pthread_create(&death, NULL, &reaper, s);
		philo_take_fork(s, philo);
		philo_eat(s, philo);
		philo_sleep(s, philo);
		philo_think(s, philo);
		i++;
	}
	pthread_detach(death);
	if (data->one_die)
		exit(42);
	if (data->meals && i == data->nb_meals)
		data->meals_finish++;
	exit(2);
}

int			launch_philosophers(t_data *data, t_philo *philo)
{
	unsigned int	i;
	t_stock			*stock;

	if (!(stock = (t_stock *)malloc(sizeof(t_stock))))
		return (0);
	stock->data = data;
	data->t_start_usec = get_time_start(MICROSEC);
	data->t_start_sec = get_time_start(MILLESEC);
	i = 0;
	while (i < data->n_philo)
	{
		stock->philo = &philo[i];
		philo[i].pid = fork();
		if (philo[i].pid == 0)
			life_philosophers(stock, &philo[i]);
		usleep(35);
		i++;
	}
	free(stock);
	return (0);
}

int			main(int ac, char **av)
{
	t_data		*data;
	t_philo		*philo;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	if (data_manager(ac, av, data))
		return (0);
	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * data->n_philo)))
		return (0);
	init_philosopher(data->n_philo, philo);
	launch_philosophers(data, philo);
	monitor(data, philo);
	free(philo);
	free(data);
	return (0);
}
