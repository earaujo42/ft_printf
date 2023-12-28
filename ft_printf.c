/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:32:11 by earaujo           #+#    #+#             */
/*   Updated: 2023/11/21 10:13:58 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_format_str(char c, va_list args, int *count);
static int	get_format_void(char c, va_list args, int *count);
static int	get_format_nbr(char c, va_list args, int *count);

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, s);
	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (get_format_str(s[i], args, &count) == -1 || \
			get_format_void(s[i], args, &count) == -1 || \
			get_format_nbr(s[i], args, &count) == -1)
				return (-1);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

static int	get_format_str(char c, va_list args, int *count)
{
	int	nb_written;

	if (c == 'c')
	{
		nb_written = ft_putchar(va_arg(args, int));
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
	}
	else if (c == 's')
	{
		nb_written = ft_putstr(va_arg(args, char *));
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
	}
	else if (c == '%')
	{
		nb_written = ft_putchar('%');
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
	}
	return (0);
}

static int	get_format_nbr(char c, va_list args, int *count)
{
	int	nb_written;

	if (c == 'd' || c == 'i')
	{
		nb_written = ft_putnbr(va_arg(args, int), count);
		return (nb_written);
	}
	else if (c == 'x')
	{
		nb_written = ft_putnbr_base(va_arg(args, unsigned int), BASELOW, count);
		return (nb_written);
	}
	else if (c == 'X')
	{
		nb_written = ft_putnbr_base(va_arg(args, unsigned int), BASE16, count);
		return (nb_written);
	}
	else if (c == 'u')
	{
		nb_written = ft_putnbr_unsigned(va_arg(args, unsigned int), count);
		return (nb_written);
	}
	return (0);
}

static int	get_format_void(char c, va_list args, int *count)
{
	int	nb_written;

	if (c == 'p')
	{
		nb_written = ft_putvoid(va_arg(args, unsigned long int), count);
		return (nb_written);
	}
	return (0);
}
