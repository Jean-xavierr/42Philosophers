/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:14:08 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/14 11:06:40 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2)
{
	int			i;
	char		*src1;
	char		*src2;

	src1 = s1;
	src2 = s2;
	i = 0;
	if (!s1)
		return (-1);
	while (src1[i] && src2[i] && src1[i] == src2[i])
		i++;
	return (src1[i] - src2[i]);
}
