/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:16:14 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/14 21:16:16 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int				ft_string_type(char *str, t_format spec)
{
	int			count;
	char		*new_str;

	count = 0;
	if (!str)
		str = "(null)";
	if (spec.precision >= 0 && (size_t)spec.precision < ft_strlen(str))
		new_str = ft_substr(str, 0, (size_t)spec.precision);
	else
		new_str = ft_strdup(str);
	if (spec.flag == 2)
		count += ft_print_str(new_str);
	if (spec.flag == 1 && spec.width > 0)
		count += ft_print_default((size_t)(spec.width) -
					ft_strlen(new_str), '0');
	else
		count += ft_print_default((size_t)(spec.width) -
					ft_strlen(new_str), ' ');
	if (spec.flag != 2)
		count += ft_print_str(new_str);
	if (spec.width < 0)
		count += ft_print_default((size_t)(ABS(spec.width)) -
					ft_strlen(new_str), ' ');
	free(new_str);
	return (count);
}
