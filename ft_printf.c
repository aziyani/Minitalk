/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:18:13 by aziyani           #+#    #+#             */
/*   Updated: 2023/01/18 23:57:12 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// -------------------------------------------------
int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	ptr;

	va_start (ptr, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i += 1;
			len = 0;
	        if (s[i] == 'd' || s[i] == 'i')
		        len += ft_putnbr(va_arg(ptr, int));
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (len);
}
// -------------------------------------------------
int	ft_putnbr(int n)
{
	int				counter;
	char			c;
	long long int	i;

	i = n;
	counter = 0;
	if (i < 0)
	{
		i *= -1;
		counter += write(1, "-", 1);
	}
	if (i <= 9 && i >= 0)
	{
		c = i + '0';
		counter += write(1, &c, 1);
	}
	if (i > 9)
	{
		counter += ft_putnbr(i / 10);
		counter += ft_putnbr(i % 10);
	}
	return (counter);
}
// -------------------------------------------------
int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
// -------------------------------------------------