/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:29:33 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/22 16:17:18 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

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
	if (current_time - philo->last_meal > data->t_die)
	{
		data->one_die = TRUE;
		pthread_mutex_lock(philo->m_display);
		if (!data->option)
			display_light_die(data, philo, current_time);
		else
			display_visual_die(data, philo, current_time);
	}
	return (NULL);
}
