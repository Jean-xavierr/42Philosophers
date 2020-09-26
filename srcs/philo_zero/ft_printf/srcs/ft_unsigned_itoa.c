/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:32:56 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/26 12:21:39 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_get_nb_size(unsigned int nb)
{
	long size;

	size = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static char		*ft_convert_int_to_char(char *str, unsigned int size,
unsigned int nb)
{
	str[size--] = '\0';
	while (nb > 0)
	{
		str[size] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (str);
}

char			*ft_unsigned_itoa(unsigned int n)
{
	unsigned int	size;
	char			*str;

	str = 0;
	size = ft_get_nb_size(n);
	if (n == 0)
		size = 2;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	if (n == 0)
	{
		str[1] = '\0';
		str[0] = '0';
	}
	else
	{
		size--;
		ft_convert_int_to_char(str, size, n);
	}
	return (str);
}
