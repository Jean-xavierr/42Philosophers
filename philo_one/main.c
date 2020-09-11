/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/11 18:12:17 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			main(int ac, char **av)
{
	// if (!parsing_argument(ac, av))
	// 	ft_printf("ok");
	start_display();
	print_event("000001", uitoemoji(1), 1);
	print_event("000001", uitoemoji(1), 1);
	print_event("000002", uitoemoji(1), 2);
	print_event("000003", uitoemoji(20), 4);
	print_event("000004", uitoemoji(300), 1);
	print_event("000004", uitoemoji(300), 1);
	print_event("000005", uitoemoji(489), 4);
	print_event("000007", uitoemoji(57), 5);
	return (0);
}