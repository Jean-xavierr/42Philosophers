/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:48:02 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/22 16:22:18 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_is_number(char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = "0123456789";
	while (tab[i])
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_is_flags(char c)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "-0123456789.*";
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_is_convers(char c)
{
	int		i;
	char	*convers;

	i = 0;
	convers = "csdiuxXp";
	while (convers[i])
	{
		if (convers[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_is_char(char c)
{
	int		i;
	char	*tab_char;

	i = 0;
	tab_char = "abefghjklmnoqrtvwyz%";
	while (tab_char[i])
	{
		if (tab_char[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_check_set(char c)
{
	if (ft_is_flags(c))
		return (1);
	else if (ft_is_convers(c))
		return (1);
	else if (ft_is_char(c))
		return (1);
	return (0);
}
