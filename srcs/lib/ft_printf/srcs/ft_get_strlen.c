/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:32:27 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/18 18:34:42 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_slen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (6);
	while (s[i])
		i++;
	return (i);
}

char	*ft_get_string_nb(t_pdata *data)
{
	char *s;

	s = NULL;
	if (data->convers == 'd' || data->convers == 'i')
		s = ft_itoa((long)data->arg);
	else if (data->convers == 'u')
		s = ft_unsigned_itoa((unsigned long)data->arg);
	else if (data->convers == 'x' || data->convers == 'X')
		s = ft_itox((unsigned long)data->arg, data);
	else if (data->convers == 'p')
		s = ft_ultox((unsigned long)data->arg);
	else if (ft_is_convers(data->convers) == 0)
	{
		s = &data->convers;
		s[1] = '\0';
	}
	return (s);
}

int		ft_get_strlen(t_pdata *data)
{
	if (data->convers == 'c')
		return (1);
	else if (data->convers == 's')
		return (ft_slen((char *)data->arg));
	else if (data->convers == 'p')
		return (ft_slen(ft_ultox((unsigned long)data->arg)) + 2);
	else if (data->convers == 'd' || data->convers == 'i')
		return (ft_slen(ft_itoa((long)data->arg)));
	else if (data->convers == 'u')
		return (ft_slen(ft_unsigned_itoa((unsigned long)data->arg)));
	else if (data->convers == 'x' || data->convers == 'X')
		return (ft_slen(ft_itox((unsigned long)data->arg, data)));
	else if (ft_is_convers(data->convers) == 0)
		return (1);
	return (0);
}
