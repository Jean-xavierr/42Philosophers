/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:15:50 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/17 17:40:37 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	prototype_time(int time)
{
	int	i;
	int len_time;

	i = 0;
	len_time = time;
	while (len_time >= 10)
	{
		len_time = len_time /10;
		i++;
	}
	while (i < 7)
	{
		printf(".");
		i++;
	}
}

void	display_time(int time)
{
	prototype_time(time);
	printf("%d ", time);
}

void	display_light(int time, int id_philo, char *event)
{
	if (event == EVENT_DIE)
		printf(COLOR_RED);
	display_time(time);
	printf("%d ", id_philo);
	printf("%s\n", event);
	printf(COLOR_RESET);
}