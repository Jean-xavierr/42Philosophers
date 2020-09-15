/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:32:41 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/15 11:36:06 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin_char(char *s1, char c)
{
	int		i;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i++] = c;
	dst[i] = '\0';
	free(s1);
	return (dst);
}
