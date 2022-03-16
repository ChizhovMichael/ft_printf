/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 22:20:42 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/14 20:22:01 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_specifier(t_format *specifier)
{
	specifier->flag = 0;
	specifier->width = 0;
	specifier->precision = -1;
	specifier->type = '\0';
	specifier->lenght = 1;
}

int		ft_var(t_format spec, va_list ap)
{
	int		count;

	count = 0;
	if (spec.type == 'c')
		count += ft_char_type(va_arg(ap, int), spec);
	else if (spec.type == 's')
		count += ft_string_type(va_arg(ap, char *), spec);
	else if (spec.type == 'p')
		count += ft_pointer_type(va_arg(ap, void *), spec);
	else if (spec.type == 'd')
		count += ft_int_type(va_arg(ap, int), spec);
	else if (spec.type == 'i')
		count += ft_int_type(va_arg(ap, int), spec);
	else if (spec.type == 'u')
		count += ft_un_int_type(va_arg(ap, unsigned int), spec);
	else if (spec.type == 'x')
		count += ft_un_xx_type(va_arg(ap, unsigned int), spec, TRUE);
	else if (spec.type == 'X')
		count += ft_un_xx_type(va_arg(ap, unsigned int), spec, FALSE);
	else if (spec.type == '%')
		count += ft_percent_type(spec);
	return (count);
}

int		ft_processor(char *format, va_list ap)
{
	int			i;
	int			count;
	t_format	spec;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_init_specifier(&spec);
			ft_parser(format, &spec, i, ap);
			if (spec.type)
				count += ft_var(spec, ap);
			i += spec.lenght;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
			i++;
		}
	}
	return (count);
}
