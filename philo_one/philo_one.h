/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:08:00 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/16 17:17:19 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHILO_ONE_H
# define __PHILO_ONE_H

# include "../lib/header/philo.h"

typedef struct				s_philo
{
	pthread_t			thread;
	pthread_mutex_t		*fork1;
	pthread_mutex_t		*fork2; 
	pthread_mutex_t		*display;
	int					id;
	int					last_meal;
	struct timeval		time_start;
}							t_philo;

#endif
