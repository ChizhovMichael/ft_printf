/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:41:26 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/20 19:02:58 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int		ft_print_default(int width, char c)
{
	int		count;

	count = 0;
	while (width > 0)
	{
		write(1, &c, 1);
		width--;
		count++;
	}
	return (count);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_create_default_str(char *str, int size, char a)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (!(new_str = (char *)malloc(size + 1)))
		return (NULL);
	while (i < size - len)
	{
		new_str[i] = a;
		i++;
	}
	while (i < size)
		new_str[i++] = str[j++];
	new_str[i] = '\0';
	return (new_str);
}
