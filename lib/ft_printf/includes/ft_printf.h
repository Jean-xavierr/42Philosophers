/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:06:37 by jereligi          #+#    #+#             */
/*   Updated: 2020/09/11 14:27:21 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_data
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
}					t_data;

/* ---> ft_printf.c <---
*/
int					ft_check_string(int i, t_data *data);
int					ft_printf(const char *s, ...);

/* ---> ft_utils.c <---
*/
void				ft_putchar(char c, t_data *data);
void				ft_reinit_flags(t_data *data);
void				ft_init(const char *s, t_data *data);

/* ---> ft_check_set.c <---
*/
int					ft_is_number(char c);
int					ft_is_flags(char c);
int					ft_is_convers(char c);
int					ft_is_char(char c);
int					ft_check_set(char c);

/* ---> ft_display_management <---
*/
void		ft_putstr(char *s, t_data *data);
void		ft_display_management(t_data *data);

/* ---> ft_flags_management.c <---
*/
void		ft_flags_management(t_data *data);

/* ---> ft_flag_management_integer.c <---
*/
void		ft_flags_management_integer(t_data *data);

/* ---> ft_exception_flag.c <---
*/
void		ft_exception_flag_zero_integer(t_data *data);
int			ft_nb_is_negative(t_data *data);
int			ft_len_nb(t_data *data);

/* ---> ft_get_strlen.c <---
*/
int			ft_strlen(char *s);
char		*ft_get_string_nb(t_data *data);
int			ft_strlen_nb_hex(long nb);
int			ft_get_strlen(t_data *data);

/* ---> ft_check_flags.c <---
*/
void		ft_call_flags_management(t_data *data);
int			ft_check_flags_zero(int	i, t_data *data);
int			ft_check_flags_precision(int i, t_data *data);

/* ---> ft_strjoin.c <---
*/
char		*ft_strjoin_char(char *s1, char c);

/* ---> ft_itoa.c <---
*/
char		*ft_itoa(int n);

/* ---> ft_unsigned_itoa.c <--
*/
char		*ft_unsigned_itoa(unsigned int n);

/* ---> ft_itox.c <---
*/
char		*ft_itox(unsigned int n, t_data *data);

/* ---> ft_ultox.c <---
*/
char		*ft_ultox(unsigned long n);

/* ---> ft_atoi.c <---
*/
int			ft_atoi(char *str, int *i);

#endif
