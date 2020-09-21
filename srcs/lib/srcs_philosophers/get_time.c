/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:13:31 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/21 17:35:37 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

unsigned int	get_time(unsigned int start_usec, unsigned int start_sec)
{
	struct timeval	current_time;
	int				sec;

	gettimeofday(&current_time, NULL);
	sec = current_time.tv_sec - start_sec;
	return (((unsigned int)(sec * 1000000 + current_time.tv_usec) - start_usec)
	/ ONE_MILLISEC);
}

unsigned int	get_time_start(int time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (time == 0)
		return (current_time.tv_usec);
	else
		return (current_time.tv_sec);
	return (0);
}
