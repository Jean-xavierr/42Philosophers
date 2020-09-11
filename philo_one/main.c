/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/11 19:18:46 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			main(int ac, char **av)
{
	// if (!parsing_argument(ac, av))
	// 	ft_printf("ok");
	start_display();
	print_event("00001", uitoemoji(1), 1);
	print_event("00001", uitoemoji(1), 1);
	print_event("00002", uitoemoji(1), 2);
	print_event("00003", uitoemoji(20), 4);
	print_event("00004", uitoemoji(300), 1);
	print_event("00004", uitoemoji(300), 1);
	print_event("00005", uitoemoji(489), 4);
	print_event("00007", uitoemoji(57), 5);


	ft_printf("\n\n");
	print_clasic_display("00001", 1, 1);
	print_clasic_display("00001", 1, 1);
	print_clasic_display("00002", 1, 2);
	print_clasic_display("00003", 20, 4);
	print_clasic_display("00004", 300, 1);
	print_clasic_display("00004", 300, 1);
	print_clasic_display("00005", 489, 4);
	print_clasic_display("00007", 57, 5);
	return (0);
}