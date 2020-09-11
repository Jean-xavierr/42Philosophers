/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:27:31 by Jeanxavier        #+#    #+#             */
/*   Updated: 2020/09/11 17:49:03 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

/* Function Global
*/
int			ft_strlen(char *s);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		**uitoemoji(int nb);
char		*ft_strjoindel(char *s1, char *s2, int param);
void		*ft_memcpy_n(void *dst, void *src, unsigned int n);

/* Function for all Philo
*/
int			parsing_argument(int ac, char **av);

void		print_event(char *time, char **id_philo, int event);
void		print_usage(void);
void		start_display(void);

#endif