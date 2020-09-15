/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:36 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/15 11:37:09 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int		fill_struct(int ac, char **av, int prog_arg, t_philo *data_philo)
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
	ft_printf("\nn_philo %d\nt_die %d\nt_eat %d\nt_sleep %d\nnb_meals %d\n", data_philo->n_philo, data_philo->t_die, data_philo->t_eat, data_philo->t_sleep, data_philo->nb_meals);
	return (0);
}

int		management_philo(int ac, char **av, t_philo *data_philo)
{
	int			prog_arg[0];

	*prog_arg = 0;
	if (!check_argument(ac, av, prog_arg))
	{
		ft_printf("parsing ok\n");
		fill_struct(ac, av, *prog_arg, data_philo);
		if (managmenent_parsing(data_philo))
			return (1);
	}
	else
		return (1);
	return (0);
}
