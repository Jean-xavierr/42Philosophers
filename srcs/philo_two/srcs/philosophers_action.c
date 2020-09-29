/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:31:22 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/29 12:15:46 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_two.h"

void		philo_take_fork(t_stock *stock, t_philo *philo)
{
	sem_wait(philo->sem_forks);
	sem_wait(philo->sem_forks);
	sem_wait(philo->sem_display);
	display_manager(stock, philo, EVENT_FORK);
	display_manager(stock, philo, EVENT_FORK);
	sem_post(philo->sem_display);
}

void		philo_eat(t_stock *s, t_philo *philo)
{
	sem_wait(philo->sem_display);
	display_manager(s, philo, EVENT_EAT);
	sem_post(philo->sem_display);
	philo->last_meal = get_time(s->data->t_start_usec, s->data->t_start_sec);
	usleep(s->data->t_eat * ONE_MILLISEC);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
}

void		philo_sleep(t_stock *stock, t_philo *philo)
{
	sem_wait(philo->sem_display);
	display_manager(stock, philo, EVENT_SLEEP);
	sem_post(philo->sem_display);
	usleep(stock->data->t_sleep * ONE_MILLISEC);
}

void		philo_think(t_stock *stock, t_philo *philo)
{
	sem_wait(philo->sem_display);
	display_manager(stock, philo, EVENT_THINK);
	sem_post(philo->sem_display);
}
