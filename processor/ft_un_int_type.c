/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:20:11 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/20 19:05:44 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_print_diff_un(char *new_str, t_format spec)
{
	int		count;

	count = 0;
	if (spec.flag == 2)
		count += ft_print_str(new_str);
	if (spec.width > 0)
		count += ft_print_default((size_t)(spec.width) -
						ft_strlen(new_str), ' ');
	if (spec.flag != 2)
		count += ft_print_str(new_str);
	if (spec.width < 0)
		count += ft_print_default((size_t)(ABS(spec.width)) -
					ft_strlen(new_str), ' ');
	return (count);
}

int			ft_print_all_un(char *unn, t_format spec)
{
	char	*temp;
	char	*new_str;
	int		count;

	count = 0;
	if (spec.precision > (int)ft_strlen(unn))
		temp = ft_create_default_str(unn, spec.precision, '0');
	else
		temp = ft_strdup(unn);
	if (spec.width > (int)ft_strlen(temp))
	{
		if (spec.flag == 1 && spec.precision < 0)
			new_str = ft_create_default_str(temp, spec.width, '0');
		else
			new_str = ft_create_default_str(temp, (int)ft_strlen(temp), ' ');
	}
	else
		new_str = ft_strdup(temp);
	count += ft_print_diff_un(new_str, spec);
	free(new_str);
	free(temp);
	return (count);
}

int			ft_un_int_type(unsigned int un, t_format spec)
{
	int		count;
	char	*unn;

	count = 0;
	if (!un && !spec.precision)
		return (ft_print_default(ABS(spec.width), ' '));
	unn = ft_itoa_base((unsigned int)un, FALSE, 10);
	count += ft_print_all_un(unn, spec);
	free(unn);
	return (count);
}
