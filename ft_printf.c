/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/19 11:03:54 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chk_type(va_list ap, t_info *info, int val)
{
	char	type;

	type = info->type;
	if (type == 'c')
		val = ft_putchr(va_arg(ap, int), info, val);
	else if (type == 's')
		val = ft_putstr(va_arg(ap, char *), info, val);
	else if (type == 'p')
		val = ft_putaddress(info, va_arg(ap, unsigned long long), val);
	else if (type == 'd' || type == 'i')
		val = ft_putnbr_fd(va_arg(ap, int), info, val);
	else if (type == 'u')
		val = ft_putnbr_fd(va_arg(ap, unsigned int), info, val);
	else if (type == 'x' || type == 'X')
		val = print_dechex(info, va_arg(ap, unsigned int), val);
	else if (type == '%')
		val = ft_putchr('%', info, val);
	else
		val = no_spec(info, val);
	return (val);
}

int	chk_flag(char *format, t_info *info, va_list ap, int i)
{
	if (format[i] == '-')
		info->min = 1;
	else if (format[i] == '0')
		info->zero = 1;
	else if (format[i] == '*' || ft_isnum(format[i]))
		i = set_width(format, info, ap, i);
	else
	{
		if (format[i] == '.')
			i = set_prec(format, info, ap, i);
	}
	return (i);
}

int	chk_loop(char format)
{
	if (ft_strchr("0-.*", format) != 0 || ft_isnum(format))
		return (1);
	else
		return (0);
}

int	chk_format(va_list ap, char *format, int val, t_info *info)
{
	int	i;

	i = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			write(1, &format[i++], 1);
			val++;
		}
		if (format[i] == '%')
		{
			init_info(info);
			i++;
			while (format[i] != '\0' && chk_loop(format[i]))
				i = chk_flag(format, info, ap, i) + 1;
			if (format[i] == '\0')
				continue ;
			else
				i = set_type(format, info, i);
			val = chk_type(ap, info, val);
		}
	}
	return (val);
}

int	ft_printf(const char *format, ...)
{
	int		val;
	t_info	*info;
	va_list	ap;

	val = 0;
	va_start(ap, format);
	info = malloc(sizeof(t_info));
	if (!info)
		return (-1);
	val = chk_format(ap, (char *)format, val, info);
	va_end(ap);
	free(info);
	return (val);
}
