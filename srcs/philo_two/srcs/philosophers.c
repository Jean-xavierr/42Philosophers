/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:35:22 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/28 16:29:01 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_two.h"

void		*life_philosophers(void *stock)
{
	unsigned int	i;
	t_stock			*s;
	t_data			*data;
	t_philo			*philo;
	pthread_t		death;

	i = 0;
	s = (t_stock *)stock;
	data = s->data;
	philo = s->philo;
	while (!data->one_die && (!data->meals || i < data->nb_meals))
	{
		pthread_detach(death);
		pthread_create(&death, NULL, &reaper, stock);
		philo_take_fork(s, philo);
		philo_eat(s, philo);
		philo_sleep(s, philo);
		philo_think(s, philo);
		i++;
	}
	pthread_detach(death);
	if (data->meals && i == data->nb_meals)
		data->meals_finish++;
	return (NULL);
}

int			launch_philosophers(t_data *data, t_philo *philo)
{
	unsigned int	i;
	t_stock			*stock;

	if (!(stock = (t_stock *)malloc(sizeof(t_stock) * (data->n_philo + 1))))
		return (0);
	stock->data = data;
	data->t_start_usec = get_time_start(MICROSEC);
	data->t_start_sec = get_time_start(MILLESEC);
	i = 0;
	while (i < data->n_philo)
	{
		stock[i].philo = &philo[i];
		stock[i].data = data;
		if (pthread_create(&philo[i].thread, NULL, &life_philosophers, &stock[i]))
			return (1);
		usleep(20);
		i++;
	}
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
