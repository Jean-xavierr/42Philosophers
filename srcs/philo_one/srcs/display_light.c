/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:32:28 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/22 16:14:43 by jereligi         ###   ########.fr       */
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

void		display_light_die(t_data *data, t_philo *philo, unsigned int time)
{
	display_time(data->option, time);
	ft_printf("%u %u is died\n", time, philo->id);
}

void		display_time(t_bool option, unsigned int time)
{
	int		len_time;

	if (option == TRUE)
		ft_printf("| ");
	len_time = len_nb(time);
	while (len_time < 7)
	{
		ft_printf(".");
		len_time++;
	}
}

void		display_manager(t_stock *s, t_philo *philo, char *event)
{
	unsigned int current_time;

	current_time = get_time(s->data->t_start_usec, s->data->t_start_sec);
	display_time(s->data->option, current_time);
	if (s->data->option == FALSE)
		ft_printf("%u %u %s\n", current_time, philo->id, event);
	else
		display_emoji(current_time, philo, event);
}
