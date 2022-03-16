/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:52:51 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/20 19:03:40 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	char		*str;

	count = 0;
	if (!(str = ft_strdup(format)))
		return (0);
	if (format)
	{
		va_start(ap, format);
		count += ft_processor(str, ap);
		va_end(ap);
	}
	free(str);
	return (count);
}
