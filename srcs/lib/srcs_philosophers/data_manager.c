/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:53:36 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/26 22:25:25 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int		fill_struct(int ac, char **av, int prog_arg, t_data *data)
{
	data->n_philo = ft_atoi(av[1 + prog_arg], 0);
	data->t_die = ft_atoi(av[2 + prog_arg], 0);
	data->t_eat = ft_atoi(av[3 + prog_arg], 0);
	data->t_sleep = ft_atoi(av[4 + prog_arg], 0);
	data->meals_finish = 0;
	if (ac == (6 + prog_arg))
	{
		data->meals = 1;
		data->nb_meals = ft_atoi(av[ac - 1], 0);
	}
	else
	{
		data->meals = 0;
		data->nb_meals = 0;
	}
	if (prog_arg == 1)
		data->option = TRUE;
	return (0);
}

int		data_manager(int ac, char **av, t_data *data)
{
	int			prog_arg[0];

	*prog_arg = 0;
	data->option = FALSE;
	data->one_die = FALSE;
	if (!check_argument(ac, av, prog_arg))
	{
		fill_struct(ac, av, *prog_arg, data);
		if (parsing_manager(data))
			return (1);
	}
	else
		return (1);
	return (0);
}
