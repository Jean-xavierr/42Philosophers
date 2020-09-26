/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:26:01 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/26 22:21:51 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_zero.h"

void		print_error_not_enought_arg(void)
{
	write(1, COLOR_RED, 5);
	write(1, "Error : ", 8);
	write(1, COLOR_RESET, 5);
	write(1, " the program need 5 or 6 arguments.\n", 36);
	print_usage();
}

void		print_error_more_arg(void)
{
	ft_printf(COLOR_RED "Error :" COLOR_RESET);
	ft_printf(" You put more arguments");
	ft_printf(", min arguments 5, max arguments 7, with option [-v]\n");
	ft_printf("\tPut the [-v] option as the first argument.\n");
	print_usage();
}

void		print_usage(void)
{
	ft_printf(COLOR_BLUE "Usage :\n" COLOR_RESET);
	ft_printf(COLOR_RED "\t./philo " COLOR_RESET);
	ft_printf(COLOR_GREEN "[-v] " COLOR_RESET);
	ft_printf("number_of_philosopher time_to_die time_to_eat time_to_sleep ");
	ft_printf("[number_of_time_each_philosophers_must_eat]\n\n");
}
