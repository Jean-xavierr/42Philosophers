/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:26:01 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/17 13:32:35 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void		print_error_not_enought_arg(int nb)
{
	printf(COLOR_RED "Error :" COLOR_RESET);
	if (nb == 5)
		printf(" the program need %d arguments.\n", nb);
	else
		printf(" the program need %d arguments if you use -v option.\n", nb);
	printf("\tThe arguments between brackets are not mandatory.\n");
	print_usage();
}

void		print_error_more_arg(void)
{
	printf(COLOR_RED "Error :" COLOR_RESET);
	printf(" You put more arguments");
	printf(", min arguments 5, max arguments 7, with option [-v]\n");
	printf("\tPut the [-v] option as the first argument.\n");
	print_usage();
}

void		print_usage(void)
{
	printf(COLOR_BLUE "Usage :\n" COLOR_RESET);
	printf(COLOR_RED "\t./philo " COLOR_RESET);
	printf(COLOR_GREEN "[-v] " COLOR_RESET);
	printf("number_of_philosopher time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_time_each_philosophers_must_eat]\n\n");
}
