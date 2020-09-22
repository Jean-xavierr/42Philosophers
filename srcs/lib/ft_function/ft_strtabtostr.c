/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabtostr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:14:00 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/22 16:14:13 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

char		*ft_strtabtostr(char **s)
{
	int		i;
	int		n;
	int		len;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	len = len * 7;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	len = 0;
	while (s[i] != NULL)
	{
		n = 0;
		while (s[i][n])
			str[len++] = s[i][n++];
		i++;
	}
	str[len++] = '\0';
	return (str);
}
