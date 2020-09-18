/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:15:41 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/18 15:38:14 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int		parsing_nb_philo(int nb)
{
	if (nb <= 1)
	{
		ft_putstr(COLOR_RED "Error : " COLOR_RESET);
		ft_putstr("number of philosophers must be greater than 1.\n");
		return (1);
	}
	if (nb > 200)
	{
		ft_putstr(COLOR_YELLOW "Warning : " COLOR_RESET);
		ft_putstr("very large number of philosophers, ");
		ft_putstr("risk of slowing down or crashing.\n");
	}
	return (0);
}

int		parsing_time_to(int time_to, int action)
{
	if (time_to <= 0)
	{
		ft_putstr(COLOR_RED "Error : " COLOR_RESET);
		if (action == 0)
			ft_putstr("time_to_die can't be less than 1.\n");
		else if (action == 1)
			ft_putstr("time_to_eat can't be less than 1.\n");
		else if (action == 2)
			ft_putstr("time_to_sleep can't be less than 1.\n");
		return (1);
	}
	else if (time_to > 0 && time_to < 60)
	{
		ft_putstr(COLOR_YELLOW "Warning : " COLOR_RESET);
		if (action == 0)
			ft_putstr("time_to_die less 60ms delay could be not enough for good result.\n");
		else if (action == 1)
			ft_putstr("time_to_eat less 60ms delay could be not enough for good result.\n");
		else if (action == 2)
			ft_putstr("time_to_sleep less 60ms delay could be not enough for good result.\n");
	}
	return (0);
}

int		parsing_number_of_meals(int nb_meals)
{
	if (nb_meals <= 0)
	{
		ft_putstr(COLOR_RED "Error : " COLOR_RESET);
		ft_putstr("number_of_time_each_philosophers_must_eat ");
		ft_putstr("can't be less than 1\n");
		return (1);
	}
	return (0);
}

int		parsing_manager(t_data *data)
{
	if (parsing_nb_philo(data->n_philo))
		return (1);
	if (parsing_time_to(data->t_die, 0))
		return (1);
	if (parsing_time_to(data->t_eat, 1))
		return (1);
	if (parsing_time_to(data->t_sleep, 2))
		return (1);
	if (data->meals == 1)
		if (parsing_number_of_meals(data->nb_meals))
			return (1);
	return (0);
}
