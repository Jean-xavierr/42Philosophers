/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoemoji.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 15:44:31 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/14 11:08:13 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

#define EMOJI_ZERO	"0️⃣"
#define EMOJI_ONE	"1️⃣"
#define EMOJI_TWO	"2️⃣"
#define EMOJI_THREE "3️⃣"
#define EMOJI_FOUR	"4️⃣"
#define EMOJI_FIVE	"5️⃣"
#define EMOJI_SIX	"6️⃣"
#define EMOJI_SEVEN "7️⃣"
#define EMOJI_EIGHT "8️⃣"
#define EMOJI_NINE	"9️⃣"

int			ft_strlen_nb(int nb)
{
	int i;

	i = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		**malloc_emojistab(char **emojis)
{
	if (!(emojis = (char **)malloc(sizeof(char *) * 11)))
		return (emojis);
	emojis[0] = ft_strdup(EMOJI_ZERO);
	emojis[1] = ft_strdup(EMOJI_ONE);
	emojis[2] = ft_strdup(EMOJI_TWO);
	emojis[3] = ft_strdup(EMOJI_THREE);
	emojis[4] = ft_strdup(EMOJI_FOUR);
	emojis[5] = ft_strdup(EMOJI_FIVE);
	emojis[6] = ft_strdup(EMOJI_SIX);
	emojis[7] = ft_strdup(EMOJI_SEVEN);
	emojis[8] = ft_strdup(EMOJI_EIGHT);
	emojis[9] = ft_strdup(EMOJI_NINE);
	emojis[10] = "\0";
	return (emojis);
}

int			get_emoji_nb(int nb, char **emoji_nb, char **emojis)
{
	int	i;
	int	tmp_nb;

	i = 0;
	while (nb > 0)
	{
		emoji_nb[i] = ft_strdup("");
		if (nb > 10)
		{
			tmp_nb = nb % 10;
			emoji_nb[i] = ft_strjoindel(ft_strjoindel(emoji_nb[i],
			emojis[tmp_nb], 1), " ", 1);
			nb = nb / 10;
		}
		else
		{
			emoji_nb[i] = ft_strjoindel(emojis[nb], " ", 0);
			nb = nb / 10;
		}
		i++;
	}
	emoji_nb[i] = NULL;
	i--;
	return (i);
}

char		**ft_strtab_swap(char **emoji_nb, int i)
{
	int		n;
	char	*tmp;

	n = 0;
	while (n < i)
	{
		tmp = emoji_nb[n];
		emoji_nb[n] = emoji_nb[i];
		emoji_nb[i] = tmp;
		n++;
		i--;
	}
	return (emoji_nb);
}

char		**uitoemoji(int nb)
{
	int		i;
	char	**emojis;
	char	**emoji_nb;

	emojis = malloc_emojistab(emojis);
	if (!(emoji_nb = (char **)malloc(sizeof(char *) * ft_strlen_nb(nb))))
		return (emojis);
	i = get_emoji_nb(nb, emoji_nb, emojis);
	ft_strtab_swap(emoji_nb, i);
	return (emoji_nb);
}
