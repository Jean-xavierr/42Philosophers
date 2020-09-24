/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:32:28 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/24 11:30:26 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_one.h"

void		display_light_die(t_data *data, t_philo *philo, unsigned int time)
{
	display_time(data->option, time);
	ft_printf("%u %u is dead\n", time, philo->id);
}

void		display_light_all_meals_ate(t_data *data, t_philo *philo,
unsigned int time)
{
	display_time(data->option, time);
	ft_printf("%u %u all the meals ate\n", time, philo->id);
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

void		display_light(unsigned int idp, unsigned int current_time,
char *event)
{
	char			*time;
	char			*id;
	char			*dot;

	dot = ".......";
	time = ft_utoa(current_time);
	id = ft_utoa(idp);
	write(1, dot, ft_strlen(dot) - len_nb(current_time));
	write(1, time, ft_strlen(time));
	write(1, " ", 1);
	write(1, id, 1);
	write(1, " ", 1);
	write(1, event, ft_strlen(event));
	write(1, "\n", 1);
	free(time);
	free(id);
}

void		display_manager(t_stock *s, t_philo *philo, char *event)
{
	unsigned int	current_time;

	current_time = get_time(s->data->t_start_usec, s->data->t_start_sec);
	if (s->data->option == FALSE)
		display_light(philo->id, current_time, event);
	else
	{
		display_time(s->data->option, current_time);
		display_emoji(current_time, philo, event);
	}
}
