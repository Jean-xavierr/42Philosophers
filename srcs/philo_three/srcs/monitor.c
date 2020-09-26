/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:40:13 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/26 18:26:53 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_three.h"

void		kill_philosophers(t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philo)
		kill(philo[i++].pid, SIGKILL);
}

void		monitor_die(t_data *data, t_philo *philo)
{
	unsigned int		i;
	int		status;

	i = 0;
	while (i < data->n_philo)
	{
		waitpid(philo[i].pid, &status, WNOHANG);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 42 || WEXITSTATUS(status) == 2)
				break ;
		}
		i++;
		if (i == data->n_philo - 1)
			i = 0;
	}
	kill_philosophers(data, philo);
	if (WEXITSTATUS(status) == 2)
		display_all_meals_ate(data);

}

void		monitor(t_data *data, t_philo *philo)
{
	monitor_die(data, philo);
}
