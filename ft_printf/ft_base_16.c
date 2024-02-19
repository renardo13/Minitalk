/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:42:33 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/15 14:02:19 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base_16(unsigned int nbr)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nbr > 15)
	{
		count += ft_base_16(nbr / 16);
		count += ft_base_16(nbr % 16);
	}
	else
	{
		write(1, &base[nbr], 1);
		count++;
	}
	return (count);
}
