/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:28:05 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/26 20:54:42 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_zero.h"

void		philo_take_fork(t_stock *stock, t_philo *philo)
{
	pthread_mutex_lock(philo->m_fork1);
	pthread_mutex_lock(philo->m_fork2);
	pthread_mutex_lock(philo->m_display);
	display_manager(stock, philo, EVENT_FORK);
	display_manager(stock, philo, EVENT_FORK);
	pthread_mutex_unlock(philo->m_display);
}

void		philo_eat(t_stock *s, t_philo *philo)
{
	pthread_mutex_lock(s->philo->m_display);
	display_manager(s, philo, EVENT_EAT);
	philo->last_meal = get_time(s->data->t_start_usec, s->data->t_start_sec);
	pthread_mutex_unlock(s->philo->m_display);
	usleep(s->data->t_eat * ONE_MILLISEC);
	pthread_mutex_unlock(philo->m_fork1);
	pthread_mutex_unlock(philo->m_fork2);
}

void		philo_sleep(t_stock *stock, t_philo *philo)
{
	pthread_mutex_lock(stock->philo->m_display);
	display_manager(stock, philo, EVENT_SLEEP);
	pthread_mutex_unlock(stock->philo->m_display);
	usleep(stock->data->t_sleep * ONE_MILLISEC);
}

void		philo_think(t_stock *stock, t_philo *philo)
{
	pthread_mutex_lock(stock->philo->m_display);
	display_manager(stock, philo, EVENT_THINK);
	pthread_mutex_unlock(stock->philo->m_display);
}
