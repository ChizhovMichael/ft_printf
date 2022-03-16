/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:46:46 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/12 17:39:24 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_parse_precision(t_format *specifier, char *format, int i, va_list ap)
{
	size_t	len;

	len = 0;
	if (format[i] && format[i] == '.')
	{
		i++;
		if (format[i] && format[i] == '*')
		{
			specifier->precision = va_arg(ap, int);
			specifier->lenght += 2;
			i++;
		}
		else
		{
			specifier->precision = ft_atoi(format + i);
			while (format[i] && ft_isdigit(format[i]))
			{
				len++;
				i++;
			}
			specifier->lenght += (1 + len);
		}
	}
	return (i);
}
