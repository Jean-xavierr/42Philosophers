/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:35:42 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/14 11:06:48 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n])
		dst[i++] = s1[n++];
	n = 0;
	while (s2[n])
		dst[i++] = s2[n++];
	dst[i] = '\0';
	return (dst);
}
