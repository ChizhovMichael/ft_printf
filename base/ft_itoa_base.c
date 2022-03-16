/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 20:43:43 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/16 20:43:46 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

char	*ft_save_str(unsigned int nb, char *str, int i,
						unsigned int base)
{
	unsigned int	temp;

	while (nb != 0)
	{
		temp = 0;
		temp = nb % base;
		if (temp < 10)
			str[i - 1] = temp + 48;
		else
			str[i - 1] = temp + 55;
		nb /= base;
		i--;
	}
	return (str);
}

char	*ft_save_str_small(unsigned int nb, char *str, int i,
						unsigned int base)
{
	unsigned int	temp;

	while (nb != 0)
	{
		temp = 0;
		temp = nb % base;
		if (temp < 10)
			str[i - 1] = temp + 48;
		else
			str[i - 1] = temp + 87;
		nb /= base;
		i--;
	}
	return (str);
}

char	*ft_itoa_base(unsigned int n, int small,
					unsigned int base)
{
	char				*str;
	unsigned int		nb;
	int					i;

	i = 0;
	nb = n;
	if (!n)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= base;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	if (small)
		str = ft_save_str_small(nb, str, i, base);
	else
		str = ft_save_str(nb, str, i, base);
	return (str);
}

char	*ft_save_str_small_8_bit(unsigned long long nb, char *str, int i)
{
	unsigned long long	temp;

	while (nb != 0)
	{
		temp = 0;
		temp = nb % 16;
		if (temp < 10)
			str[i - 1] = temp + 48;
		else
			str[i - 1] = temp + 87;
		nb /= 16;
		i--;
	}
	return (str);
}

char	*ft_itoa_base_8_bit(unsigned long long n)
{
	char					*str;
	unsigned long long		nb;
	int						i;

	i = 0;
	nb = n;
	if (!n)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	str = ft_save_str_small_8_bit(nb, str, i);
	return (str);
}
