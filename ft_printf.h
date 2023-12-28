/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:12:42 by earaujo           #+#    #+#             */
/*   Updated: 2023/11/21 10:13:44 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE10 "0123456789"
# define BASELOW "0123456789abcdef"
# define BASE16 "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_printf(const char *s, ...);
int	ft_putstr(char *s);
int	ft_putnbr_base(unsigned int nbr, char *base, int *count);
int	ft_putvoid(unsigned long int nbr, int *count);
int	ft_putnbr_unsigned(unsigned int nbr, int *count);
int	ft_putnbr(int n, int *count);

#endif
