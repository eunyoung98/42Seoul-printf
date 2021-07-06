/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dechex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/18 19:09:30 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_left(unsigned int num, t_info *info, int val)
{
	int	temp;
	int	len;

	len = nbr_len(num, info->type) + info->nbr_minus;
	val = chk_minus(info, val);
	if (info->prec >= nbr_len(num, info->type) + info->nbr_minus)
	{
		temp = info->prec - nbr_len(num, info->type);
		while (temp-- > 0)
		{
			write(1, "0", 1);
			len++;
			val++;
		}
	}
	print_nbr(num, info->type);
	val += nbr_len(num, info->type);
	while ((info->width)-- > len)
	{
		write(1, " ", 1);
		val++;
	}
	return (val);
}

int	print_right(unsigned int num, t_info *info, int val)
{
	char	type;

	type = info->type;
	val = print_star(num, info, val);
	val = chk_minus(info, val);
	if (info->dot == 1 && info->prec >= nbr_len(num, type) + info->nbr_minus)
		val = print_zero(num, info, val);
	print_nbr(num, type);
	val += nbr_len(num, type);
	return (val);
}

int	is_dechex_dot(unsigned int num, t_info *info, int val)
{
	if (info->min == 1)
		val = print_left(num, info, val);
	else
		val = print_right(num, info, val);
	return (val);
}

int	no_dot(unsigned int num, t_info *info, int val)
{
	if (info->min == 1)
	{
		val = chk_minus(info, val);
		print_nbr(num, info->type);
		val += nbr_len(num, info->type);
		val = print_star(num, info, val);
	}
	else if (info->zero == 1)
	{
		val = chk_minus(info, val);
		val = print_zero(num, info, val);
		print_nbr(num, info->type);
		val += nbr_len(num, info->type);
	}
	else
		val = print_right(num, info, val);
	return (val);
}

int	print_dechex(t_info *info, unsigned int num, int val)
{
	if (info->prec < 0)
		info->dot = 0;
	if (info->dot == 1 && info->prec == 0 && num == 0)
	{
		while ((info->width)-- > 0)
		{
			write(1, " ", 1);
			val++;
		}
		return (val);
	}
	if (info->zero == 1 && info->dot == 1)
		info->zero = 0;
	else if (info->zero == 1 && info->dot == 0 && info->min == 1)
		info->zero = 0;
	if (info->dot == 1)
		val = is_dechex_dot(num, info, val);
	else
		val = no_dot(num, info, val);
	return (val);
}
