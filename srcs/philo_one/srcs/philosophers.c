/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/21 17:15:34 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

void		*life_philosophers(void *stock)
{
	unsigned int	i;
	t_stock			*s;
	t_data			*data;
	t_philo			*philo;

	i = 0;
	s = (t_stock *)stock;
	data = s->data;
	philo = s->philo;
	while (!data->meals || i < data->nb_meals)
	{
		philo_take_fork(s, philo);
		philo_eat(s, philo);
		philo_sleep(s, philo);
		philo_think(s, philo);
		i++;
	}
	return (NULL);
}

int			launch_philosophers(t_data *data, t_philo *philo)
{
	unsigned int	i;
	t_stock			*stock;

	if (!(stock = (t_stock *)malloc(sizeof(t_stock))))
		return (0);
	if (!(stock->philo = (t_philo *)malloc(sizeof(t_philo) * data->n_philo)))
		return (0);
	stock->data = data;
	data->t_start_usec = get_time_start(MICROSEC);
	data->t_start_sec = get_time_start(MILLESEC);
	i = 0;
	while (i < data->n_philo)
	{
		stock->philo = &philo[i];
		if (pthread_create(&philo[i].thread, NULL, &life_philosophers, stock))
			return (1);
		usleep(35);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
		pthread_join(philo[i++].thread, NULL);
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
	return (0);
}
