/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:29:15 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/21 17:15:54 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int		ulen(unsigned int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void			ft_strrev(char *str)
{
	char			*t_begin;
	char			*t_end;
	unsigned int	len;
	char			temp;

	t_begin = str;
	t_end = str;
	len = ft_strlen(str);
	while (*t_end)
		t_end++;
	t_end--;
	while (t_begin - str < len / 2)
	{
		temp = *t_begin;
		*t_begin = *t_end;
		*t_end = temp;
		t_begin++;
		t_end--;
	}
}

char			*ft_utoa(unsigned int n)
{
	char *str;
	char *temp;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (ulen(n) + 1))))
		return (NULL);
	temp = str;
	while (n != 0)
	{
		*temp = (n % 10) + '0';
		n /= 10;
		temp++;
	}
	temp++;
	*temp = '\0';
	ft_strrev(str);
	return (str);
}
