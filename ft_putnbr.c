/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:51:42 by earaujo           #+#    #+#             */
/*   Updated: 2023/11/20 10:39:17 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_neg(int *n, int c, int *count);

int	ft_putnbr(int n, int *count)
{
	int	nb_written;
	int	c;

	c = n;
	nb_written = ft_putnbr_neg(&n, c, count);
	if ((nb_written == 1 && c != 1) || (nb_written == -1 && c != -1))
		return (nb_written);
	if (n < 10)
	{
		nb_written = ft_putchar('0' + n);
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	return (0);
}

int	ft_putnbr_neg(int *n, int c, int *count)
{
	int	nb_written;

	if (*n == -2147483648)
	{
		nb_written = ft_putstr("-2147483648");
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
		return (1);
	}
	if (*n < 0)
	{
		nb_written = ft_putchar('-');
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
		*n = *n * -1;
	}
	return (c);
}

int	ft_putnbr_base(unsigned int nbr, char *base, int *count)
{
	int	nb_written;

	if (nbr < 16)
	{
		nb_written = ft_putchar(base[nbr]);
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
	}
	else
	{
		ft_putnbr_base((nbr / 16), base, count);
		ft_putnbr_base((nbr % 16), base, count);
	}
	return (0);
}

int	ft_putnbr_unsigned(unsigned int nbr, int *count)
{
	int	nb_written;

	if (nbr <= 9)
	{
		nb_written = ft_putchar(BASE10[nbr % 10]);
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
	}
	else
	{
		ft_putnbr_unsigned((nbr / 10), count);
		ft_putnbr_unsigned((nbr % 10), count);
	}
	return (0);
}
