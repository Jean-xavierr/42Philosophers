/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:26:01 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/18 15:16:37 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void		print_error_not_enought_arg(int nb)
{
	ft_putstr(COLOR_RED "Error :" COLOR_RESET);
	if (nb == 5)
		ft_putstr(" the program need 4 arguments.\n");
	else
		ft_putstr(" the program need 5 arguments if you use -v option.\n");
	ft_putstr("\tThe arguments between brackets are not mandatory.\n");
	print_usage();
}

void		print_error_more_arg(void)
{
	ft_putstr(COLOR_RED "Error :" COLOR_RESET);
	ft_putstr(" You put more arguments");
	ft_putstr(", min arguments 5, max arguments 7, with option [-v]\n");
	ft_putstr("\tPut the [-v] option as the first argument.\n");
	print_usage();
}

void		print_usage(void)
{
	ft_putstr(COLOR_BLUE "Usage :\n" COLOR_RESET);
	ft_putstr(COLOR_RED "\t./philo " COLOR_RESET);
	ft_putstr(COLOR_GREEN "[-v] " COLOR_RESET);
	ft_putstr("number_of_philosopher time_to_die time_to_eat time_to_sleep ");
	ft_putstr("[number_of_time_each_philosophers_must_eat]\n\n");
}
