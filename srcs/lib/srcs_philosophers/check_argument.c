/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:32:07 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/26 22:25:01 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int			check_classic_mode_arg(int ac, char **av, int *prog_arg)
{
	if (ac != 5 && ac != 6)
	{
		if (ac < 5)
			print_error_not_enought_arg();
		else
			print_error_more_arg();
		return (1);
	}
	if (!ft_strcmp(av[1], "-v"))
		prog_arg[0] = 1;
	else
		prog_arg[0] = 0;
	return (0);
}

int			check_argument(int ac, char **av, int *prog_arg)
{
	if (check_classic_mode_arg(ac, av, prog_arg))
		return (1);
	return (0);
}
