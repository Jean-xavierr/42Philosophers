/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:00:06 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/27 09:55:02 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_check_string_null(t_data *data)
{
	int		i;
	int		precision;
	char	*str;
	char	*tmp;

	i = 0;
	str = "(null)";
	tmp = (char *)data->arg;
	if (data->precision == -1 || data->precision > 6)
		precision = 6;
	else
		precision = data->precision;
	if (data->convers == 's')
	{
		if (tmp == NULL)
		{
			while (i < precision)
				ft_putchar(str[i++], data);
			return (1);
		}
	}
	return (0);
}

void		ft_putstr(char *s, t_data *data)
{
	int	i;
	int	precision;

	i = 0;
	precision = data->precision;
	if (ft_check_string_null(data) == 1)
		return ;
	if (data->convers == 'p')
	{
		ft_putchar('0', data);
		ft_putchar('x', data);
	}
	if ((data->convers != 's' && data->convers != 'c') && (data->precision >= 0
	&& s[0] != '0'))
		precision = -1;
	if (precision >= 0)
		while (i < precision && s[i])
			ft_putchar(s[i++], data);
	else
		while (s[i])
			ft_putchar(s[i++], data);
}

void		ft_display_management(t_data *data)
{
	if (data->convers == 'c')
		ft_putchar((char)data->arg, data);
	else if (data->convers == 's')
		ft_putstr((char *)data->arg, data);
	else if (data->convers == 'd' || data->convers == 'i')
		ft_putstr(ft_itoa((int)data->arg), data);
	else if (data->convers == 'u')
		ft_putstr(ft_unsigned_itoa((unsigned int)data->arg), data);
	else if (data->convers == 'x' || data->convers == 'X')
		ft_putstr(ft_itox((unsigned int)data->arg, data), data);
	else if (data->convers == 'p')
		ft_putstr(ft_ultox((unsigned long)data->arg), data);
	else if (ft_is_convers(data->convers) == 0)
		ft_putchar(data->convers, data);
}
