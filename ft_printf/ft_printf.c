/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:40:36 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/15 18:41:13 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(arg, int));
	else if (c == '%')
		count = ft_putchar('%');
	else if (c == 's')
		count = ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count = ft_putunbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		count = ft_base_16(va_arg(arg, unsigned long long));
	else if (c == 'p')
		count += ft_ptr_null(va_arg(arg, unsigned long long));
	else if (c == 'X')
		count += ft_base_16_maj(va_arg(arg, unsigned int));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int	count;
	int	i;

	va_list(arg);
	va_start(arg, s);
	if (!s)
		return (-1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			count += ft_parse(arg, s[i++ + 1]);
		else if (s[i] == '%' && !s[i + 1])
			return (-1);
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}

/* int main ()
{
  char *ptr;
  ptr = "Coucou les zouzou";

  char *ptr7;
  ptr7 = "Coucou les zouzou";

  int n;
  int u;

  u = ft_printf("%s%", ptr7);
  n = ft_printf("%s%", ptr7);
  ft_printf("\n");
  ft_printf ("%d\n", u);
  ft_printf ("%d\n", n);
} */
