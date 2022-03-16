/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:12:37 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/12 20:23:10 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_type(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') ||
			(c == 'd') || (c == 'i') || (c == 'u') ||
			(c == 'x') || (c == 'X') || (c == '%'));
}

void	ft_parse_type(t_format *specifier, char *format, int i)
{
	if (format[i] && is_type(format[i]))
	{
		specifier->type = format[i];
		specifier->lenght += 1;
	}
}
