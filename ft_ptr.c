/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:54:58 by asay              #+#    #+#             */
/*   Updated: 2025/07/07 18:34:45 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += ft_str("(nil)");
	else
	{
		len += ft_str("0x");
	// C'de standart olarak adrsi formatının başında 0x bulunuyor.
		len += ft_hex((unsigned long)ptr);
	// bellek adresleri hexadecimal tutulduğ için pointer'ın tuttuğu adresi hex'e ceviriyoruz.
	}
	return (len);
}
