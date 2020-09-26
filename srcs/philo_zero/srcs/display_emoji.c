/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_emoji.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:39:06 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/26 20:53:37 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_zero.h"

void		display_emoji_dead(t_data *data, t_philo *philo, unsigned int time)
{
	display_time(data->option, time);
	ft_printf("%u ", time);
	print_id_philo(philo);
	ft_printf(COLOR_RED "is dead" COLOR_RESET);
	ft_printf("             💀 |\n");
	ft_printf("└------------------------------------------┘\n\n");
}

void		display_all_meals_ate(t_data *data)
{
	unsigned int time;

	time = get_time(data->t_start_usec, data->t_start_sec);
	if (data->option)
	{
		display_time(data->option, time);
		ft_printf("%u          "COLOR_GREEN"  all the meals ate 🙇", time);
		ft_printf(COLOR_RESET"   |\n");
		ft_printf("└------------------------------------------┘\n\n");
	}
	else
	{
		display_time(data->option, time);
		ft_printf("%u %u all the meals ate\n", time);
	}
}

void		print_id_philo(t_philo *philo)
{
	int		i;
	int		n;
	char	**id_emoji;
	char	*id;

	i = len_nb(philo->id);
	id_emoji = uitoemoji(philo->id);
	id = ft_strtabtostr(id_emoji);
	n = 0;
	while (id_emoji[n])
		free(id_emoji[n++]);
	free(id_emoji);
	if (i == 1)
		ft_printf("    %s    ", id);
	else if (i == 2)
		ft_printf("   %s   ", id);
	else if (i == 3)
		ft_printf("  %s  ", id);
	free(id);
}

void		display_visual(void)
{
	ft_printf("┌----------┰-------┰-----------------------┐\n");
	ft_printf("| Time     | Philo | Event                 |\n");
	ft_printf("|----------┸-------┸-----------------------|\n");
}

void		display_emoji(unsigned int time, t_philo *philo, char *event)
{
	ft_printf("%u ", time);
	print_id_philo(philo);
	if (!ft_strcmp(EVENT_FORK, event))
		ft_printf("has taken a fork    🍴 |\n");
	else if (!ft_strcmp(EVENT_EAT, event))
		ft_printf("is eating           🍜 |\n");
	else if (!ft_strcmp(EVENT_SLEEP, event))
		ft_printf("is sleeping         😴 |\n");
	else if (!ft_strcmp(EVENT_THINK, event))
		ft_printf("is thinking         💭 |\n");
}
