/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:43:53 by earaujo           #+#    #+#             */
/*   Updated: 2023/11/21 10:13:20 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	complete_void(unsigned long int nbr, int *count);

int	ft_putvoid(unsigned long int nbr, int *count)
{
	int	nb_written;

	if (nbr == 0)
	{
		nb_written = ft_putstr("(nil)");
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
		return (nb_written);
	}
	nb_written = ft_putstr("0x");
	if (nb_written == -1)
		return (-1);
	*count += nb_written;
	complete_void(nbr, count);
	return (0);
}

static int	complete_void(unsigned long int nbr, int *count)
{
	int	nb_written;

	if (nbr < 16)
	{
		nb_written = ft_putchar(BASELOW[nbr]);
		if (nb_written == -1)
			return (-1);
		*count += nb_written;
	}
	if (nbr >= 16)
	{
		complete_void((nbr / 16), count);
		complete_void((nbr % 16), count);
	}
	return (0);
}
