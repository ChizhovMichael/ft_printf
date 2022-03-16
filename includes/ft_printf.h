/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:19:15 by tgildero          #+#    #+#             */
/*   Updated: 2020/12/20 19:04:27 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define TRUE 1
# define FALSE 0
# define ABS(Value) Value > 0 ? Value : (-1) * Value

typedef	struct		s_format
{
	int				flag;
	int				width;
	int				precision;
	char			type;
	int				lenght;
}					t_format;

int					ft_printf(const char *format, ...);
int					ft_processor(char *format, va_list ap);
int					ft_char_type(char c, t_format spec);
int					ft_percent_type(t_format spec);
int					ft_string_type(char *str, t_format spec);
int					ft_un_xx_type(unsigned int xx, t_format spec, int small);
int					ft_un_int_type(unsigned int un, t_format spec);
int					ft_pointer_type(void *ptr, t_format spec);
int					ft_int_type(int d, t_format spec);

void				ft_parser(char *format, t_format *spec, int i, va_list ap);
int					ft_parse_flags(t_format *specifier, char *format, int i);
int					ft_parse_width(t_format *specifier, char *format,
									int i, va_list ap);
int					ft_parse_precision(t_format *specifier, char *format,
									int i, va_list ap);
void				ft_parse_type(t_format *specifier, char *format, int i);

int					ft_print_default(int width, char c);
int					ft_putchar(char c);
int					ft_print_str(char *str);
char				*ft_create_default_str(char *str, int size, char a);
char				*ft_itoa_base(unsigned int n, int small, unsigned int base);
char				*ft_itoa_base_8_bit(unsigned long long n);

#endif
