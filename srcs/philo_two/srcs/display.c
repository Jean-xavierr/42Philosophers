/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:33:12 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/24 17:54:26 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_two.h"

void		display_all_meals_ate(t_data *data)
{
	char			*time;
	char			*dot;
	unsigned int	current_time;

	current_time = get_time(data->t_start_usec, data->t_start_sec);
	dot = ".......";
	time = ft_utoa(current_time);
	write(1, dot, ft_strlen(dot) - len_nb(current_time));
	write(1, time, ft_strlen(time));
	free(time);
	write(1, "   ", 3);
	write(1, "all the meals ate\n\n", 19);
}

void		display_manager(t_stock *s, t_philo *philo, char *event)
{
	char			*time;
	char			*id;
	char			*dot;
	unsigned int	current_time;

	current_time = get_time(s->data->t_start_usec, s->data->t_start_sec);
	dot = ".......";
	time = ft_utoa(current_time);
	id = ft_utoa(philo->id);
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
