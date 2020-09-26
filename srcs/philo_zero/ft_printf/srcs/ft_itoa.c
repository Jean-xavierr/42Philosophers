/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:38:53 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/26 13:54:24 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_get_nb_size(long nb, int n)
{
	long size;

	size = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	if (n < 0)
		size++;
	return (size);
}

static char		*ft_convert_int_to_char(char *str, long size, long nb, int n)
{
	str[size--] = '\0';
	while (nb > 0)
	{
		str[size] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	if (n < 0)
		str[size] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	long	size;
	long	nb;
	char	*str;

	str = 0;
	if (n < 0)
		nb = (long)n * -1;
	else
		nb = (long)n;
	size = ft_get_nb_size(nb, n);
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
		ft_convert_int_to_char(str, size, nb, n);
	}
	return (str);
}
