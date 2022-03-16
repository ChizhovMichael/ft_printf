/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:12:28 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/20 19:14:52 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int			ft_print_diff_int(char *new_str, t_format spec)
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

int			is_negative(int d)
{
	if (d >= 0)
		return (0);
	return (1);
}

int			ft_print_all_int(int d, char *temp, t_format spec)
{
	char	*new_temp;
	char	*new_str;
	int		count;

	count = 0;
	if (spec.width - is_negative(d) > (int)ft_strlen(temp))
	{
		if (spec.flag == 1 && spec.precision < 0)
			new_temp = ft_create_default_str(temp, spec.width -
					is_negative(d), '0');
		else
			new_temp = ft_create_default_str(temp, (int)ft_strlen(temp), ' ');
	}
	else
		new_temp = ft_strdup(temp);
	if (is_negative(d))
		new_str = ft_strjoin("-", new_temp);
	else
		new_str = ft_strdup(new_temp);
	count += ft_print_diff_int(new_str, spec);
	free(new_str);
	free(new_temp);
	return (count);
}

int			ft_int_type(int d, t_format spec)
{
	int		count;
	char	*dd;
	char	*new_dd;
	char	*temp;

	count = 0;
	if (!d && !spec.precision)
		return (ft_print_default(ABS(spec.width), ' '));
	dd = ft_itoa(d);
	if (d < 0)
		new_dd = ft_substr(dd, 1, ft_strlen(dd) - 1);
	else
		new_dd = ft_strdup(dd);
	if (spec.precision > (int)ft_strlen(new_dd))
		temp = ft_create_default_str(new_dd, spec.precision, '0');
	else
		temp = ft_strdup(new_dd);
	count += ft_print_all_int(d, temp, spec);
	free(dd);
	free(new_dd);
	free(temp);
	return (count);
}
