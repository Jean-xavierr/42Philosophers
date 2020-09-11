/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:50:54 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/19 17:00:29 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->return_printf++;
}

void	ft_reinit_flags(t_data *data)
{
	if (!(data->set = (char *)malloc(sizeof(char *))))
		return ;
	data->set[0] = '\0';
	data->flags = '~';
	data->width = 0;
	data->precision = -1;
	data->convers = 0;
	data->arg = 0;
}

void	ft_init(const char *s, t_data *data)
{
	data->str = (char *)s;
	data->set = 0;
	data->flags = '~';
	data->width = 0;
	data->precision = -1;
	data->convers = 0;
	data->arg = 0;
	data->return_printf = 0;
}
