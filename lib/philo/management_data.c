/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:36 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/17 16:15:40 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int		fill_struct(int ac, char **av, int prog_arg, t_data_philo *data_philo)
{
	data_philo->n_philo = ft_atoi(av[1 + prog_arg], 0);
	data_philo->t_die = ft_atoi(av[2 + prog_arg], 0);
	data_philo->t_eat = ft_atoi(av[3 + prog_arg], 0);
	data_philo->t_sleep = ft_atoi(av[4 + prog_arg], 0);
	if (ac == (6 + prog_arg))
	{
		data_philo->meals = 1;
		data_philo->nb_meals = ft_atoi(av[ac - 1], 0);
	}
	else
	{
		data_philo->meals = 0;
		data_philo->nb_meals = 0;
	}
	if(prog_arg == 1)
		data_philo->option = 1;
	return (0);
}

int		management_data(int ac, char **av, t_data_philo *data_philo)
{
	int			prog_arg[0];

	*prog_arg = 0;
	data_philo->option = 0;
	if (!check_argument(ac, av, prog_arg))
	{
		fill_struct(ac, av, *prog_arg, data_philo);
		if (managmenent_parsing(data_philo))
			return (1);
	}
	else
		return (1);
	return (0);
}
