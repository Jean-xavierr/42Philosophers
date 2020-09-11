/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:11:46 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/27 10:38:15 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_flag_width(t_data *data)
{
	int	precision;

	if (data->precision >= 0 && ft_get_strlen(data) > data->precision)
		precision = data->precision;
	else if (ft_get_strlen(data) != 0)
		precision = ft_get_strlen(data);
	else
		precision = 0;
	while (precision++ < data->width)
		ft_putchar(' ', data);
	ft_display_management(data);
}

static void		ft_flag_zero(t_data *data)
{
	int	precision;

	precision = 0;
	if (ft_nb_is_negative(data))
		ft_exception_flag_zero_integer(data);
	else
	{
		if (data->precision > 0)
			precision = data->precision;
		else
			precision = ft_get_strlen(data);
		while (precision++ < data->width)
			ft_putchar('0', data);
		ft_display_management(data);
	}
}

static void		ft_flag_minus(t_data *data)
{
	int	precision;

	ft_display_management(data);
	if (data->precision >= 0 && ft_get_strlen(data) > data->precision)
		precision = data->precision;
	else
		precision = ft_get_strlen(data);
	while (precision++ < data->width)
		ft_putchar(' ', data);
}

void			ft_flags_management(t_data *data)
{
	if (data->convers != 's' && data->convers != 'c')
		ft_flags_management_integer(data);
	else if (data->flags == '-')
		ft_flag_minus(data);
	else if (data->flags == '0')
		ft_flag_zero(data);
	else if (data->width > 0)
		ft_flag_width(data);
	else
		ft_display_management(data);
}
