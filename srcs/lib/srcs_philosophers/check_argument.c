/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:32:07 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/18 18:58:59 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int			check_classic_mode_arg(int ac, int *prog_arg)
{
	if (ac != 5 && ac != 6)
	{
		if (ac < 5)
			print_error_not_enought_arg(5);
		else
			print_error_more_arg();
		return (1);
	}
	prog_arg[0] = 0;
	return (0);
}

int			check_visual_mode_arg(int ac, int *prog_arg)
{
	if (ac != 6 && ac != 7)
	{
		if (ac < 6)
			print_error_not_enought_arg(6);
		else
			print_error_more_arg();
		return (1);
	}
	prog_arg[0] = 1;
	return (0);
}

int			check_argument(int ac, char **av, int *prog_arg)
{
	if (!ft_strncmp(av[1], "-v"))
		return (check_visual_mode_arg(ac, prog_arg));
	else
		return (check_classic_mode_arg(ac, prog_arg));
	return (0);
}
