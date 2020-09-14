/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:43:46 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/14 11:06:52 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

char			*ft_strjoindel(char *s1, char *s2, int param)
{
	char	*i_new;
	char	*new;

	if (!(new = (char*)malloc(sizeof(char)
	* ((ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	i_new = new;
	if (s1 || s2)
	{
		i_new = ft_memcpy_n(i_new, s1, ft_strlen(s1));
		i_new = ft_memcpy_n(i_new, s2, ft_strlen(s2));
	}
	*i_new = '\0';
	if (param == 1)
		free(s1);
	if (param == 2)
		free(s2);
	if (param == 3)
	{
		free(s1);
		free(s2);
	}
	return (new);
}
