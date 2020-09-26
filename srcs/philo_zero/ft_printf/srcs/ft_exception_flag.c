/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:16:04 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/18 18:34:42 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_exception_flag_zero_integer(t_pdata *data)
{
	int		precision;
	int		len_nb;
	int		width;
	char	*s;

	len_nb = ft_get_strlen(data);
	if (data->precision > data->width)
		ft_putchar('-', data);
	width = data->width;
	if (data->precision > 0 || data->width > 0)
		precision = data->precision + 1;
	else
		precision = len_nb;
	while (width-- > precision && precision > 0 && width >= len_nb)
		ft_putchar(' ', data);
	if (data->width >= data->precision)
		ft_putchar('-', data);
	while (((precision-- > data->width && precision >= len_nb) ||
		(width-- >= len_nb)) || precision >= len_nb)
		ft_putchar('0', data);
	s = ft_itoa((long)data->arg);
	ft_putstr(&s[1], data);
}

int			ft_nb_is_negative(t_pdata *data)
{
	char *str_nb;

	str_nb = 0;
	if (data->convers == 'd' || data->convers == 'i')
	{
		str_nb = ft_itoa((long)data->arg);
		if (str_nb[0] == '-')
			return (1);
	}
	return (0);
}

int			ft_len_nb(t_pdata *data)
{
	int		len_nb;
	char	*s;

	s = ft_get_string_nb(data);
	len_nb = ft_get_strlen(data);
	if (s[0] == '0' && data->precision == 0)
		len_nb = 0;
	return (len_nb);
}
