/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:32:07 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/11 13:54:05 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int			parsing_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		if (ac < 5)
		{
			ft_printf(COLOR_RED "Error :" COLOR_RESET);
			ft_printf(" the program need 4 arguments\n");
			print_usage();
		}
		else
		{
			ft_printf(COLOR_RED "Error :" COLOR_RESET);
			ft_printf(" You put more arguments");
			ft_printf(", min arguments 4, max arguments 5\n");
			print_usage();
		}
		return (1);
	}
	return (0);
}