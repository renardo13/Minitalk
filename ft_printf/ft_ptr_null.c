/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:42:40 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/15 14:02:14 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long long nbr, int count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
	{
		count += ft_ptr(nbr / 16, 0);
		count += ft_ptr(nbr % 16, 0);
	}
	else
	{
		write(1, &base[nbr], 1);
		count++;
	}
	return (count);
}

int	ft_ptr_null(unsigned long long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	count = ft_ptr(nbr, count);
	return (count);
}
