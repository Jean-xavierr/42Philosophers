/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:32:28 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/21 17:14:33 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

int			len_nb(unsigned int nb)
{
	int		i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void		display_time(unsigned int time)
{
	int		len_time;

	len_time = len_nb(time);
	while (len_time < 7)
	{
		ft_printf(".");
		len_time++;
	}
}

void		display_visual(unsigned int time, t_philo *philo, char *event)
{
	ft_printf("visual: %u %u %s\n", time, philo->id, event);
}

void		display_manager(t_stock *s, t_philo *philo, char *event)
{
	unsigned int current_time;

	current_time = get_time(s->data->t_start_usec, s->data->t_start_sec);
	display_time(current_time);
	if (s->data->option == FALSE)
		ft_printf("%u %u %s\n", current_time, philo->id, event);
	else
		display_visual(current_time, philo, event);
}
