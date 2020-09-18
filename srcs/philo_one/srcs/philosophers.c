/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/18 15:38:14 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

int			main(int ac, char **av)
{
	t_data		*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (0);
	if (data_manager(ac, av, data))
		return (1);
	return (0);
}
