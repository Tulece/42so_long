/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:04:38 by anporced          #+#    #+#             */
/*   Updated: 2023/10/19 18:11:33 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
size_t	ft_nbrlen(int nbr, int base);
size_t	ft_nbrlen_unsigned(unsigned long long nbr, int base);
int		ft_putnbr_unsigned(unsigned int nbr);
int		ft_putnbr_hex(unsigned long long nbr);
int		ft_putnbr_x(unsigned long int nbr, int check);
int		ft_putptr(unsigned long long ptr);
int		ft_format(va_list arg, const char format);
int		ft_printf(char const *str, ...);
int		ft_putnbr_ptr(unsigned long long nbr);

#endif
