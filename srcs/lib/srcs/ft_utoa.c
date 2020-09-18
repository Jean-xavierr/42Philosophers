/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:29:15 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/18 15:33:21 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static char		*ft_strdup(char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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