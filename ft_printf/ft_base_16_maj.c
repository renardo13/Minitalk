/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_16_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:44:58 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/15 14:02:22 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_16_maj(unsigned long int nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (nb > 15)
	{
		count += ft_base_16_maj(nb / 16);
		count += ft_base_16_maj(nb % 16);
	}
	else
	{
		write(1, &base[nb], 1);
		count++;
	}
	return (count);
}
