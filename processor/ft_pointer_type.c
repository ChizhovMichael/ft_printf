/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:57:09 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/20 19:08:01 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_print_nil(char *str, t_format spec)
{
	int		count;

	count = 0;
	if (spec.flag == 2)
		count += ft_print_str(str);
	count += ft_print_default(spec.width - 2, ' ');
	if (spec.flag != 2)
		count += ft_print_str(str);
	return (count);
}

int			ft_print_diff_ptr(char *new_str, t_format spec)
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

int			ft_print_all_ptr(char *ptrr, t_format spec)
{
	char	*temp;
	char	*new_temp;
	char	*new_str;
	int		count;

	count = 0;
	if (spec.precision > (int)ft_strlen(ptrr))
		temp = ft_create_default_str(ptrr, spec.precision, '0');
	else
		temp = ft_strdup(ptrr);
	if (spec.width > (int)ft_strlen(temp))
	{
		if (spec.flag == 1 && spec.precision < 0)
			new_temp = ft_create_default_str(temp, spec.width, '0');
		else
			new_temp = ft_create_default_str(temp, (int)ft_strlen(temp), ' ');
	}
	else
		new_temp = ft_strdup(temp);
	new_str = ft_strjoin("0x", temp);
	count += ft_print_diff_ptr(new_str, spec);
	free(new_str);
	free(temp);
	free(new_temp);
	return (count);
}

int			ft_pointer_type(void *ptr, t_format spec)
{
	int		count;
	char	*ptrr;

	count = 0;
	if (!ptr && !spec.precision)
		return (ft_print_nil("0x", spec));
	ptrr = ft_itoa_base_8_bit((unsigned long long)ptr);
	count += ft_print_all_ptr(ptrr, spec);
	free(ptrr);
	return (count);
}
