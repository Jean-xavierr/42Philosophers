/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:29:33 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/29 12:10:42 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_zero.h"

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
		pthread_mutex_lock(philo->m_display);
		data->one_die = TRUE;
		if (!data->option)
			display_light_dead(data, philo, current_time);
		else
			display_emoji_dead(data, philo, current_time);
	}
	return (NULL);
}
