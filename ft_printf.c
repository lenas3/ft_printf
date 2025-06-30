/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:36:42 by asay              #+#    #+#             */
/*   Updated: 2025/06/30 22:34:26 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_putnbr(int nb)
{
	int i;
	
	i = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		write(1, "2147483648", 10);
		return 0;
	}
	if (nb < 0)
	{
		i = 1;
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		i++;
	}
	ft_putchar('0' + nb % 10);

	return (i);
}

int ft_str(char *str)
{
	int i;
	
	i = -1;
	while(str[++i])
		write(1, &str[i], 1);
	//write(1, "\n", 1);
	return (i);
}

int form(char x, va_list args)
{
	if (x == 's')
		return (ft_str(va_arg(args, char *)));	
	else if (x == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (x == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if(x == '%')
		return (ft_putchar('%'));
	return (0);
}

int ft_printf(const char *str, ...)
{
	int i;
	int sum;
	char kar;
	va_list args;
	va_start(args, str); // va_start cagrisi her zaman % kontrolunden once olmali.
	
	i = 0;
	sum = 0;
	while(str[i])
	{
		if(str[i] == '%')
		{
			i++;
			sum += form(str[i], args);
			i++;
		}
		else
			sum += ft_putchar(str[i++]);
	}
	va_end(args);
	return (sum);
}

int main()
{
	ft_printf("Hello %s! Number: %d, Char: %c, Percent: %%\n", "world", 42, 'A');
	return 0;
}
