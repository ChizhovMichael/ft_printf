/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:29:50 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/12 22:03:01 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void		ft_parser(char *format, t_format *spec, int i, va_list ap)
{
	if (format[i])
	{
		i = ft_parse_flags(spec, format, ++i);
		i = ft_parse_width(spec, format, i, ap);
		i = ft_parse_precision(spec, format, i, ap);
		ft_parse_type(spec, format, i);
	}
}
