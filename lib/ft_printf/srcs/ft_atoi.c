/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:15:19 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/20 13:57:57 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str, int *n)
{
	int i;
	int	nb;
	int	negpos;

	i = 0;
	nb = 0;
	negpos = 1;
	while ((str[i] == ' ') || (str[i] > 6 && str[i] < 14))
		i++;
	if (str[i] == '-')
		negpos = negpos * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	n = n + i;
	nb = nb * negpos;
	return (nb);
}
