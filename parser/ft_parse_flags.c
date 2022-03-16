/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:22:22 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/12 17:58:29 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define FLG_NONE	0b00000000
#define FLG_ONE		0b00000001
#define FLG_TWO		0b00000010

int		is_flag(char c)
{
	return (c == '0' || c == '-');
}

int		ft_parse_flags(t_format *specifier, char *format, int i)
{
	unsigned char	flags;
	size_t			len;

	flags = FLG_NONE;
	len = 0;
	while (format[i] && is_flag(format[i]))
	{
		if (format[i] == '0')
			flags = flags | FLG_ONE;
		if (format[i] == '-')
			flags = flags | FLG_TWO;
		i++;
		len++;
	}
	if (flags & FLG_ONE)
		specifier->flag = 1;
	if (flags & FLG_TWO)
		specifier->flag = 2;
	if ((flags & FLG_ONE) && (flags & FLG_TWO))
		specifier->flag = 2;
	specifier->lenght += len;
	return (i);
}
