/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:06:37 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/26 20:56:49 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../../../lib/header/philo.h"

typedef struct		s_pdata
{
	va_list		ap;
	char		*str;
	char		*set;
	char		flags;
	int			width;
	int			precision;
	char		convers;
	void		*arg;
	int			return_printf;
}					t_pdata;

/*
** ---> ft_printf.c <---
*/
int					ft_check_string(int i, t_pdata *data);
int					ft_printf(const char *s, ...);

/*
**  ---> ft_utils.c <---
*/
void				ft_putchar(char c, t_pdata *data);
void				ft_reinit_flags(t_pdata *data);
void				ft_init(const char *s, t_pdata *data);

/*
** ---> ft_check_set.c <---
*/
int					ft_is_number(char c);
int					ft_is_flags(char c);
int					ft_is_convers(char c);
int					ft_is_char(char c);
int					ft_check_set(char c);

/*
** ---> ft_display_management <---
*/
void				ft_putstr(char *s, t_pdata *data);
void				ft_display_management(t_pdata *data);

/*
** ---> ft_flags_management.c <---
*/
void				ft_flags_management(t_pdata *data);

/*
** ---> ft_flag_management_integer.c <---
*/
void				ft_flags_management_integer(t_pdata *data);

/*
** ---> ft_exception_flag.c <---
*/
void				ft_exception_flag_zero_integer(t_pdata *data);
int					ft_nb_is_negative(t_pdata *data);
int					ft_len_nb(t_pdata *data);

/*
** ---> ft_get_strlen.c <---
*/
char				*ft_get_string_nb(t_pdata *data);
int					ft_strlen_nb_hex(long nb);
int					ft_get_strlen(t_pdata *data);
int					ft_slen(char *s);

/*
** ---> ft_check_flags.c <---
*/
void				ft_call_flags_management(t_pdata *data);
int					ft_check_flags_zero(int	i, t_pdata *data);
int					ft_check_flags_precision(int i, t_pdata *data);

/*
** ---> ft_strjoin_char.c <---
*/
char				*ft_strjoin_char(char *s1, char c);

/*
** ---> ft_itoa.c <---
*/
char				*ft_itoa(int n);

/*
** ---> ft_unsigned_itoa.c <--
*/
char				*ft_unsigned_itoa(unsigned int n);

/*
** ---> ft_itox.c <---
*/
char				*ft_itox(unsigned int n, t_pdata *data);

/*
** ---> ft_ultox.c <---
*/
char				*ft_ultox(unsigned long n);

#endif
