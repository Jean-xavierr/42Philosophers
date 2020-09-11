/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_management_integer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:15:11 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/27 10:38:26 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_flag_precision(t_data *data)
{
	int		i;
	int		len_nb;
	char	*s;

	i = 0;
	len_nb = ft_get_strlen(data);
	s = ft_get_string_nb(data);
	if (ft_nb_is_negative(data))
		ft_exception_flag_zero_integer(data);
	else if (data->precision > len_nb)
	{
		while (data->precision-- > len_nb)
			ft_putchar('0', data);
		while (s[i])
			ft_putchar(s[i++], data);
	}
	else
		while (s[i])
			ft_putchar(s[i++], data);
}

static void		ft_flag_width(t_data *data)
{
	int			len_nb;
	int			precision;
	int			width;
	char		*s;

	s = ft_get_string_nb(data);
	len_nb = ft_get_strlen(data);
	precision = data->precision;
	if (s[0] == '0' && precision == 0)
		len_nb = 0;
	if (ft_nb_is_negative(data))
	{
		s = &s[1];
		precision++;
	}
	width = data->width;
	if (ft_nb_is_negative(data) && data->precision > data->width)
		ft_putchar('-', data);
	while (width-- > precision && width >= len_nb)
		ft_putchar(' ', data);
	if (ft_nb_is_negative(data) && data->width >= data->precision)
		ft_putchar('-', data);
	while (precision-- > len_nb)
		ft_putchar('0', data);
	ft_putstr(s, data);
}

static void		ft_flag_zero(t_data *data)
{
	int		len_nb;
	int		precision;
	int		width;

	len_nb = ft_len_nb(data);
	precision = 0;
	width = data->width;
	if (ft_nb_is_negative(data))
		ft_exception_flag_zero_integer(data);
	else
	{
		if (data->precision >= 0)
			precision = data->precision;
		else
			precision = ft_get_strlen(data);
		while (width-- > data->precision && data->precision >= 0 &&
		width >= len_nb)
			ft_putchar(' ', data);
		while ((precision-- > data->width && precision >= len_nb) ||
		(width-- >= len_nb))
			ft_putchar('0', data);
		ft_display_management(data);
	}
}

static void		ft_flag_minus(t_data *data)
{
	int		len_nb;
	int		precision;
	int		precision_tmp;
	char	*s;

	s = ft_get_string_nb(data);
	len_nb = ft_get_strlen(data);
	precision = data->precision;
	if (s[0] == '0' && precision == 0)
		len_nb = 0;
	if (data->precision == -1)
		precision = 0;
	if (ft_nb_is_negative(data))
	{
		ft_putchar('-', data);
		s = &s[1];
		precision++;
	}
	precision_tmp = precision;
	while (precision-- > len_nb)
		ft_putchar('0', data);
	ft_putstr(s, data);
	while (data->width-- > precision_tmp && data->width >= len_nb)
		ft_putchar(' ', data);
}

void			ft_flags_management_integer(t_data *data)
{
	if (data->flags == '-' && data->width > 0)
		ft_flag_minus(data);
	else if (data->flags == '0')
		ft_flag_zero(data);
	else if (data->width > 0)
		ft_flag_width(data);
	else if (data->precision > 0)
		ft_flag_precision(data);
	else
		ft_display_management(data);
}
