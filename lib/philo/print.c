/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:15:50 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/11 19:27:19 by Jeanxavier       ###   ########.fr       */
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
		ft_printf("has taken a fork    🍴  |\n");
	else if (event == 2)
		ft_printf("is eating           🍜  |\n");
	else if (event == 3)
		ft_printf("is sleeping         😴  |\n");
	else if (event == 4)
		ft_printf("is thinking         💭  |\n");
	else if (event == 5)
	{
		ft_printf(COLOR_RED "is died" COLOR_RESET);
		ft_printf("             ☠️  |\n");
		ft_printf("└------------------------------------------┘\n");
	}
}

void		print_usage(void)
{
	ft_printf(COLOR_BLUE "Usage :\n" COLOR_RESET);
	ft_printf(COLOR_RED "\t./philo " COLOR_RESET);
	ft_printf("number_of_philosopher time_to_die time_to_eat time_to_sleep ");
	ft_printf("[number_of_time_each_philosophers_must_eat]\n");
}