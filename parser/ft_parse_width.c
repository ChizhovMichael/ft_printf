/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:02:17 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/12 17:55:07 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_parse_width(t_format *specifier, char *format, int i, va_list ap)
{
	size_t	len;

	len = 0;
	if (format[i] == '*')
	{
		specifier->width = va_arg(ap, int);
		i++;
		len++;
	}
	else if (ft_isdigit(format[i]))
	{
		specifier->width = ft_atoi(format + i);
		while (format[i] && ft_isdigit(format[i]))
		{
			i++;
			len++;
		}
	}
	specifier->lenght += len;
	return (i);
}
