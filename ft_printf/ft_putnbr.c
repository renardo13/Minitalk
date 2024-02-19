/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:45:06 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/15 14:02:06 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long int	nb;
	int			count;

	nb = nbr;
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		count++;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
		count++;
	}
	return (count);
}
