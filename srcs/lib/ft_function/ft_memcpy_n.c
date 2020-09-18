/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:44:48 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/14 11:06:36 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy_n(void *dst, void *src, unsigned int n)
{
	unsigned char *t_dst;
	unsigned char *t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	while (t_dst - (unsigned char*)dst < n)
	{
		*t_dst = *t_src;
		t_dst++;
		t_src++;
	}
	return (t_dst);
}
