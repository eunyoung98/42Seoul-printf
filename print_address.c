/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/18 17:38:21 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	address_star(t_info *info, unsigned long long num, int val)
{
	int	len;

	if (info->dot == 1 && info->prec == 0 && num == 0)
		len = 0;
	else
		len = nbr_len(num, info->type);
	while ((info->width)-- > (len + 2))
	{
		write(1, " ", 1);
		val++;
	}
	return (val);
}

int	address_left(t_info *info, unsigned long long num, int val)
{
	write(1, "0x", 2);
	val += 2;
	if (!(info->dot == 1 && info->prec == 0 && num == 0))
	{
		write_nbr(num, info->type, 16);
		val += nbr_len(num, info->type);
	}
	if (info->star == 1)
		val = address_star(info, num, val);
	return (val);
}

int	address_right(t_info *info, unsigned long long num, int val)
{
	if (info->star == 1)
		val = address_star(info, num, val);
	write(1, "0x", 2);
	val += 2;
	while (info->prec > nbr_len(num, info->type))
	{
		info->prec--;
		write(1, "0", 1);
		val++;
	}
	if (!(info->dot == 1 && info->prec == 0 && num == 0))
	{
		write_nbr(num, info->type, 16);
		val += nbr_len(num, info->type);
	}
	return (val);
}

int	ft_putaddress(t_info *info, unsigned long long num, int val)
{
	if (info->min == 1)
		val = address_left(info, num, val);
	else
		val = address_right(info, num, val);
	return (val);
}
