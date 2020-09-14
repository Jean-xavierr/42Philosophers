/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:15:50 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/14 12:33:08 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void		start_display(void)
{
	ft_printf("┌----------┰-------┰-----------------------┐\n");
	ft_printf("| Time     | Philo | Event                 |\n");
	ft_printf("|----------┸-------┸-----------------------|\n");
}

void		print_time(char *time, int event)
{
	if (event == 5)
	{
		ft_printf("|");
		ft_printf(COLOR_RED " %s" COLOR_RESET, time);
	}
	else
		ft_printf("| %s", time);
}

void		print_id_philo(char **id_philo)
{
	int i;

	i = 0;
	while (id_philo[i])
		i++;
	if (i == 1)
		ft_printf("         ");
	else if (i == 2)
		ft_printf("       ");
	else if (i == 3)
		ft_printf("     ");
	i = 0;
	while (id_philo[i])
		ft_printf("%s", id_philo[i++]);
	ft_printf("  ");
}

void		print_event(char *time, char **id_philo, int event)
{
	print_time(time, event);
	print_id_philo(id_philo);
	if (event == 1)
		ft_printf("has taken a fork    🍴 |\n");
	else if (event == 2)
		ft_printf("is eating           🍜 |\n");
	else if (event == 3)
		ft_printf("is sleeping         😴 |\n");
	else if (event == 4)
		ft_printf("is thinking         💭 |\n");
	else if (event == 5)
	{
		ft_printf(COLOR_RED "is died" COLOR_RESET);
		ft_printf("              ☠️ |\n");
		ft_printf("└------------------------------------------┘\n");
	}
}

void		print_clasic_display(char *time, int id_philo, int event)
{
	if (event == 5)
	{
		ft_printf(COLOR_RED "%s ", time);
		ft_printf("%d " COLOR_RESET, id_philo);
	}
	else
	{
		ft_printf("%s ", time);
		ft_printf("%d ", id_philo);
	}
	if (event == 1)
		ft_printf("has taken a fork\n");
	else if (event == 2)
		ft_printf("is eating\n");
	else if (event == 3)
		ft_printf("is sleeping\n");
	else if (event == 4)
		ft_printf("is thinking\n");
	else if (event == 5)
		ft_printf(COLOR_RED "is died\n" COLOR_RESET);
}
