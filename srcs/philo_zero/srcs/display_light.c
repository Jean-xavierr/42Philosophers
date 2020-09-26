/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:32:28 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/26 20:54:09 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo_zero.h"

void		display_light_dead(t_data *data, t_philo *philo, unsigned int time)
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
	char			*str;

	str = NULL;
	dot = ".......";
	time = ft_utoa(current_time);
	id = ft_utoa(idp);
	str = strndup(dot, ft_strlen(dot) - len_nb(current_time));
	str = ft_strjoindel(str, time, 3);
	str = ft_strjoindel(str, " ", 1);
	str = ft_strjoindel(str, id, 3);
	str = ft_strjoindel(str, " ", 1);
	str = ft_strjoindel(str, event, 1);
	str = ft_strjoindel(str, "\n", 1);
	write(1, str, ft_strlen(str));
	free(str);
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
