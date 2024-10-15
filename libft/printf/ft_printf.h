/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:31:12 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 11:57:05 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
int				ft_printstr(char *str);
void			ft_putstr(char *str);
int				ft_printptr(void *nbr);
int				ft_putptrhex(unsigned long nbr, const char c);
int				ft_printnbr(int nbr);
int				ft_utoa(unsigned int nbr);
unsigned int	ft_usize(unsigned int nbr);
int				ft_pstr(char *str);

#endif