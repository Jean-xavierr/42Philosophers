/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:15:50 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/11 13:52:33 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void		print_usage(void)
{
	ft_printf(COLOR_BLUE "Usage :\n" COLOR_RESET);
	ft_printf(COLOR_RED "\t./philo " COLOR_RESET);
	ft_printf("number_of_philosopher time_to_die time_to_eat time_to_sleep ");
	ft_printf("[number_of_time_each_philosophers_must_eat]\n");
}