/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:36:42 by asay              #+#    #+#             */
/*   Updated: 2025/07/10 16:54:36 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	form(char x, va_list args)
{
	char	*str;

	if (x == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		return (ft_str(str));
	}
	else if (x == 'd' || x == 'i')
		return (ft_nbr(va_arg(args, int)));
	else if (x == 'c')
		return (ft_char((char)va_arg(args, int)));
	else if (x == '%')
		return (ft_char('%'));
	else if (x == 'p')
		return (ft_ptr(va_arg(args, void *)));
	else if (x == 'x')
		return (ft_hex((long)va_arg(args, unsigned int)));
	else if (x == 'X')
		return (ft_uphex((long)va_arg(args, unsigned int)));
	else if (x == 'u')
		return (ft_unnbr(va_arg(args, unsigned int)));
	return (0);
}

static int	ft_hasvalid(const char *str, int j)
{
	int	count;

	count = 0;
	while (str[j] != '\0')
	{
		if (str[j] == 'c' || str[j] == 's' || str[j] == 'p' || str[j] == 'd'
			|| str[j] == 'i' || str[j] == 'u' || str[j] == 'x'
			|| str[j] == 'X' || str[j] == '%')
		{
			return (2);
			count++;
		}
		else
			j++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_hasvalid(str, i + 1) == 2)
			{
				i++;
				count += form(str[i], args);
				i++;
			}
			else
				return (0);
		}
		else
			count += ft_char(str[i++]);
	}
	va_end(args);
	return (count);
}
