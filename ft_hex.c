/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:01:24 by asay              #+#    #+#             */
/*   Updated: 2025/07/09 18:53:45 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(size_t nb)
{
	char	*set;
	int		len;

	set = "0123456789abcdef";
	len = 0;
	if (nb < 0)
	{
		ft_char('-');
		len++;
		nb = nb * -1;
	}
	if (nb < 16)
	{
		len += ft_char(set[nb]);
	}
	if (nb >= 16)
	{
		len += ft_hex((nb / 16));
		len += ft_hex((nb % 16));
	}
	return (len);
}
