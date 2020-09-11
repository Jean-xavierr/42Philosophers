/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_classic_display.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:58:03 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/11 19:32:19 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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