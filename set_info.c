/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/16 13:21:44 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->min = 0;
	info->zero = 0;
	info->star = 0;
	info->width = 0;
	info->dot = 0;
	info->prec = 0;
	info->nbr_minus = 0;
	info->type = 0;
}

int	set_type(char *format, t_info *info, int i)
{
	if (ft_strchr("cspdiuxX%%", format[i]))
		info->type = format[i++];
	else
		info->type = 'n';
	return (i);
}

int	set_width(char *format, t_info *info, va_list ap, int i)
{
	int	width;

	width = 0;
	info->star = 1;
	if (format[i] == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->min = 1;
			info->width = -info->width;
		}
	}
	else
	{
		while (ft_isnum(format[i]))
			width = width * 10 + (format[i++] - '0');
		i--;
		info->width = width;
	}
	return (i);
}

int	set_prec(char *format, t_info *info, va_list ap, int i)
{
	int	prec;

	prec = 0;
	info->dot = 1;
	i++;
	if (ft_isnum(format[i]))
	{
		while (ft_isnum(format[i]))
			prec = prec * 10 + (format[i++] - '0');
		i--;
		info->prec = prec;
	}
	else if (format[i] == '*')
		info->prec = va_arg(ap, int);
	else
	{
		info->prec = 0;
		i--;
	}
	return (i);
}
