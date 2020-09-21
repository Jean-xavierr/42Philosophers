/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:28:05 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/21 17:15:01 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

void		philo_take_fork(t_stock *stock, t_philo *philo)
{
	pthread_mutex_lock(philo->m_fork1);
	pthread_mutex_lock(philo->m_display);
	display_manager(stock, philo, EVENT_FORK);
	pthread_mutex_unlock(philo->m_display);
	pthread_mutex_lock(philo->m_fork2);
	pthread_mutex_lock(philo->m_display);
	display_manager(stock, philo, EVENT_FORK);
	pthread_mutex_unlock(philo->m_display);
}

void		philo_eat(t_stock *stock, t_philo *philo)
{
	pthread_mutex_lock(stock->philo->m_display);
	display_manager(stock, philo, EVENT_EAT);
	pthread_mutex_unlock(stock->philo->m_display);
	usleep(stock->data->t_eat * 1000);
	pthread_mutex_unlock(philo->m_fork1);
	pthread_mutex_unlock(philo->m_fork2);
}

void		philo_sleep(t_stock *stock, t_philo *philo)
{
	pthread_mutex_lock(stock->philo->m_display);
	display_manager(stock, philo, EVENT_SLEEP);
	pthread_mutex_unlock(stock->philo->m_display);
	usleep(stock->data->t_sleep * 1000);
}

void		philo_think(t_stock *stock, t_philo *philo)
{
	pthread_mutex_lock(stock->philo->m_display);
	display_manager(stock, philo, EVENT_THINK);
	pthread_mutex_unlock(stock->philo->m_display);
}
