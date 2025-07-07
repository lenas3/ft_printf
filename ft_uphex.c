/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:34:42 by asay              #+#    #+#             */
/*   Updated: 2025/07/07 18:30:19 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uphex(int nb)
{
	char	*set;
	int		len;

	len = 0;
	set = "0123456789ABCDEF";
	if (nb < 0)
	{
		ft_char('-');
		nb = nb * -1;
		len++;
	}
	if (nb < 16)
	{
		ft_char(set[nb]);
		len++;
	}
	if (nb >= 16)
	{
		len += ft_uphex((nb / 16));
		len += ft_uphex((nb % 16));
	}
	return (len);
}
