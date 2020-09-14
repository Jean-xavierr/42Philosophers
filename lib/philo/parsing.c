/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:15:41 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/14 14:55:31 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int		parsing_nb_philo(int nb)
{
	if (nb <= 1)
	{
		ft_printf(COLOR_RED "Error : " COLOR_RESET);
		ft_printf("number of philosophers must be greater than 1\n");
		return (1);
	}
	if (nb > 200)
	{
		ft_printf(COLOR_YELLOW "Warning : " COLOR_RESET);
		ft_printf("very large number of philosophers, ");
		ft_printf("risk of slowing down or crashing\n");
	}
	return (0);
}

int		parsing_time_to(int time_to, char *s)
{
	if (time_to <= 0)
	{
		ft_printf(COLOR_RED "Error : " COLOR_RESET);
		ft_printf("%s can't be less than 1\n", s);
		return (1);
	}
	else if (time_to > 0 && time_to < 60)
	{
		ft_printf(COLOR_YELLOW "Warning : " COLOR_RESET);
		ft_printf("%s -60ms delay could be not enough for good result\n", s);
	}
	return (0);
}

int		parsing_number_of_meals(int nb_meals)
{
	if (nb_meals < 0)
	{
		ft_printf(COLOR_RED "Error : " COLOR_RESET);
		ft_printf("number_of_time_each_philosophers_must_eat ");
		ft_printf("can't be less than 1\n");
		return (1);
	}
	return (0);
}

int		managmenent_parsing(t_philo *data_philo)
{
	if (parsing_nb_philo(data_philo->n_philo))
		return (1);
	if (parsing_time_to(data_philo->t_die, "time_to_die"))
		return (1);
	if (parsing_time_to(data_philo->t_eat, "time_to_eat"))
		return (1);
	if (parsing_time_to(data_philo->t_sleep, "time_to_sleep"))
		return (1);	
	if (data_philo->nb_meals != 0)
		if (parsing_number_of_meals(data_philo->nb_meals))
			return (1);
	return (0);
}