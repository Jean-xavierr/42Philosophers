/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:54:30 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/24 17:50:01 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_two.h"

void		init_philosopher(unsigned int n_philo, t_philo *philo)
{
	unsigned int	i;
	sem_t			*sem_forks;
	sem_t			*sem_display;

	i = 0;
	sem_unlink("fork");
	sem_unlink("display");
	sem_forks = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, n_philo);
	sem_display = sem_open("display", O_CREAT | O_EXCL, S_IRWXU, 1);
	while (i < n_philo)
	{
		philo[i].sem_forks = sem_forks;
		philo[i].sem_display = sem_display;
		philo[i].id = i + 1;
		philo[i].is_dead = 0;
		philo[i].last_meal = 0;
		i++;
	}
}
