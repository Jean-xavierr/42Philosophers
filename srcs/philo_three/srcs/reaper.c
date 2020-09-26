/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:38:40 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/26 18:23:45 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_three.h"

void		*reaper(void *stock)
{
	t_stock			*s;
	t_data			*data;
	t_philo			*philo;
	unsigned int	current_time;

	s = (t_stock *)stock;
	data = s->data;
	philo = s->philo;
	usleep(data->t_die * ONE_MILLISEC);
	current_time = get_time(data->t_start_usec, data->t_start_sec);
	if (current_time - philo->last_meal >= data->t_die)
	{
		sem_wait(philo->sem_display);
		data->one_die = TRUE;
		display_manager(s, philo, EVENT_DEAD);
		exit (42);
	}
	return (NULL);
}