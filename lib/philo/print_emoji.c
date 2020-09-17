/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_emoji.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:59:12 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/17 16:09:23 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void		start_display(void)
{
	printf("┌----------┰-------┰-----------------------┐\n");
	printf("| Time     | Philo | Event                 |\n");
	printf("|----------┸-------┸-----------------------|\n");
}

void		print_id_philo(char **id_philo)
{
	int i;

	i = 0;
	while (id_philo[i])
		i++;
	if (i == 1)
		printf("         ");
	else if (i == 2)
		printf("       ");
	else if (i == 3)
		printf("     ");
	i = 0;
	while (id_philo[i])
		printf("%s", id_philo[i++]);
	printf("  ");
}

void		print_event(char *time, char **id_philo, int event)
{
	print_id_philo(id_philo);
	if (event == 1)
		printf("has taken a fork    🍴 |\n");
	else if (event == 2)
		printf("is eating           🍜 |\n");
	else if (event == 3)
		printf("is sleeping         😴 |\n");
	else if (event == 4)
		printf("is thinking         💭 |\n");
	else if (event == 5)
	{
		printf(COLOR_RED "is died" COLOR_RESET);
		printf("              ☠️ |\n");
		printf("└------------------------------------------┘\n");
	}
}