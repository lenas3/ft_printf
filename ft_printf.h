/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:37:38 by asay              #+#    #+#             */
/*   Updated: 2025/07/12 13:16:50 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_char(char c);
int	ft_hex(size_t nb);
int	ft_uphex(size_t nb);
int	ft_ptr(void *ptr);
int	ft_str(char *str);
int	ft_unnbr(unsigned int i);
int	ft_nbr(int nb);

#endif
