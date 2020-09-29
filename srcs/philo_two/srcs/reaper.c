/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:02:25 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/29 12:06:10 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_two.h"

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
	if (philo->life && current_time - philo->last_meal >= data->t_die)
	{
		sem_wait(philo->sem_display);
		data->one_die = TRUE;
		display_manager(s, philo, EVENT_DEAD);
	}
	return (NULL);
}
