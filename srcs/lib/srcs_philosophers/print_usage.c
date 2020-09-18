/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:26:01 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/18 18:58:52 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void		print_error_not_enought_arg(int nb)
{
	ft_printf(COLOR_RED "Error :" COLOR_RESET);
	if (nb == 5)
		ft_printf(" the program need %d arguments.\n", nb);
	else
		ft_printf(" the program need %d arguments if you use -v option.\n", nb);
	ft_printf("\tThe arguments between brackets are not mandatory.\n");
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
