/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/16 17:02:29 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_star(char *s, t_info *info, int val)
{
	if (info->dot == 1)
		while ((info->width)-- > info->prec)
		{
			write(1, " ", 1);
			val++;
		}
	else if (info->dot == 0)
		while ((info->width)-- > ft_strlen(s))
		{
			write(1, " ", 1);
			val++;
		}
	return (val);
}

int	str_zero(char *s, t_info *info, int val)
{
	while ((info->width)-- > ft_strlen(s))
	{
		write(1, "0", 1);
		val++;
	}
	return (val);
}

int	is_str(char *s, t_info *info, int val)
{
	int	len;

	if (info->dot == 1)
		len = info->prec;
	else
		len = ft_strlen(s);
	if (info->min == 1)
	{
		write(1, s, len);
		val += len;
		if (info->star == 1)
			val = str_star(s, info, val);
	}
	else
	{
		if (info->zero == 1)
			val = str_zero(s, info, val);
		else if (info->star == 1)
			val = str_star(s, info, val);
		write(1, s, len);
		val += len;
	}
	return (val);
}

int	str_null(t_info *info, int val)
{
	if (info->min == 1)
	{
		if (info->prec < 0 || info->prec >= 6 || info->dot == 0)
			info->prec = 6;
		write(1, "(null)", info->prec);
		while ((info->width)-- > info->prec)
		{
			write(1, " ", 1);
			val++;
		}
	}
	else
	{
		if (info->prec < 0 || info->prec >= 6 || info->dot == 0)
			info->prec = 6;
		while ((info->width)-- > info->prec)
		{
			write(1, " ", 1);
			val++;
		}
		write(1, "(null)", info->prec);
	}
	return (val + info->prec);
}

int	ft_putstr(char *s, t_info *info, int val)
{
	if (!s)
	{
		val = str_null(info, val);
		return (val);
	}
	if (info->prec >= ft_strlen(s) || info->prec < 0)
		info->prec = ft_strlen(s);
	val = is_str(s, info, val);
	return (val);
}
