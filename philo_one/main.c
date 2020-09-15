/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/15 12:19:39 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"



int			main(int ac, char **av)
{
	t_philo		data_philo[0];

	if (management_philo(ac, av, data_philo))
	{
		ft_printf("\nparsing error\n");
	}
	return (0);
}