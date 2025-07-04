/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:36:42 by asay              #+#    #+#             */
/*   Updated: 2025/07/04 22:02:18 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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


static int form(char x, va_list args)
{
	if (x == 's')
		return (ft_str(va_arg(args, char *)));	
	else if (x == 'd' || x == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (x == 'c')
		return (ft_putchar((char)va_arg(args, int)));
/* 
	Default Argument Promotion: variadic fonksiyonlar çağrıldığında küçük tamsaı tipleri büyük tam sayı tiplerine yükseltilit.
		Sebep?
 		bellekte uyumu sağlamak, argümanları standart bit boyutta kullanmak için fonksiyon çağrısı sırasında 
		argümanlar int olarak alınır. Eğer direkt int yerine char almış olsaydık va_arg'ın aldığı boyut ve tip,
		argümanın bellek alanı ile uyuşmazdı. Yani gerçek argğman int olarak 4 byte kaplarken 1 byte gönderilmiş olacaktı.
*/
		
	else if (x == '%')
		return (ft_putchar('%'));
	else if (x == 'p')
		return (ft_ptr(va_arg(args, void *)));
	else if (x == 'x')
		return (ft_hex((long)va_arg(args, unsigned int)));
// long'a cast'ledik. buna 'explicit conversion' == 'type casting' deniyo. işaret değişimlerinde overflow'u engellemek için long'a çeviriyoruz.

	else if(x == 'X')
		return (ft_uphex((long)va_arg(args, unsigned int)));
	else if (x == 'u')
		return ((unsigned int)ft_putnbr(va_arg(args, int)));
	return (x);
}
int ft_isvalid(char a)
{
		if(a == 'c' || a == 's' ||a == 'p'||a == 'd'
			||a == 'i'|| a == 'u' || a == 'x' || a == 'X' || a == '%'){
			return (1);
		}
		return (0);
}

int ft_printf(const char *str, ...)
{
	int i;
	int count;
	va_list args;
	va_start(args, str); // va_start cagrisi her zaman % kontrolunden once olmali.
	// variable str is crucial otherwise i dunno how many args are.

	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == '%')
		{
				i++;
				count += form(str[i], args);
				i++;
		}
		if(str[i] == ' ')
		{
			if(ft_isvalid(str[i]))
				i++;
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int main()
{
	printf("original:%123");
	printf("\n---\n");
	ft_printf("asay:%123");
}
