/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:40:13 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/29 14:43:25 by jereligi         ###   ########.fr       */
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

int			check_status(t_data *data, t_philo *philo, unsigned int *n_philo,
unsigned int i)
{
	int					status;

	status = 0;
	waitpid(philo[i].pid, &status, WNOHANG);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 42)
			return (42);
		else if (WEXITSTATUS(status) == 2)
		{
			*n_philo = *n_philo + 1;
			if (*n_philo == data->n_philo)
				return (2);
		}
	}
	return (0);
}

void		monitor_die(t_data *data, t_philo *philo)
{
	unsigned int		i;
	unsigned int		n_philo;
	int					status;

	i = 0;
	n_philo = 0;
	while (i < data->n_philo)
	{
		status = check_status(data, philo, &n_philo, i);
		if (status == 42 || status == 2)
			break ;
		i++;
		if (i == data->n_philo)
			i = 0;
	}
	kill_philosophers(data, philo);
	if (status == 2)
		display_all_meals_ate(data);
}

void		monitor(t_data *data, t_philo *philo)
{
	monitor_die(data, philo);
}
