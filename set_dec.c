/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/18 13:49:28 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_nbr(unsigned int num, char x)
{
	char			nbr_index;
	unsigned int	base;

	if (x == 'x' || x == 'X' || x == 'p')
		base = 16;
	else
		base = 10;
	if (num >= base)
	{
		print_nbr(num / base, x);
		print_nbr(num % base, x);
	}
	else
	{
		if (x == 'x' || x == 'p')
			nbr_index = "0123456789abcdef"[num % base];
		else if (x == 'X')
			nbr_index = "0123456789ABCDEF"[num % base];
		else
			nbr_index = "0123456789"[num % base];
		write(1, &nbr_index, 1);
	}
}

int					chk_minus(t_info *info, int val)
{
	if (info->nbr_minus == 1)
	{
		write(1, "-", 1);
		val++;
	}
	return (val);
}

int					min_int(t_info *info, int val)
{
	info->nbr_minus = 1;
	val = print_dechex(info, 2147483648, val);
	return (val);
}

int					ft_putnbr_fd(int n, t_info *info, int val)
{
	if (info->type == 'd' || info->type == 'i')
	{
		if (n == -2147483648)
		{
			val = min_int(info, val);
			return (val);
		}
		if (n < 0)
		{
			info->nbr_minus = 1;
			n = -n;
		}
		val = print_dechex(info, n, val);
	}
	else
	{
		if (n < 0)
			val = print_dechex(info, n + 4294967296, val);
		else
			val = print_dechex(info, n, val);
	}
	return (val);
}
