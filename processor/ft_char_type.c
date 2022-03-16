/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:26:16 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/14 20:26:18 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_char_type(char c, t_format spec)
{
	int		count;

	count = 0;
	if (spec.flag == 2)
		count += ft_putchar(c);
	if (spec.width > 0)
		count += ft_print_default(spec.width - 1, ' ');
	if (spec.flag != 2)
		count += ft_putchar(c);
	if (spec.width < 0)
		count += ft_print_default(ABS(spec.width) - 1, ' ');
	return (count);
}
