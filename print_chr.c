/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/18 13:50:35 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chr_star(t_info *info, int val)
{
	if (info->zero == 1)
	{
		while ((info->width)-- > 1)
		{
			write(1, "0", 1);
			val++;
		}
	}
	else
	{
		while ((info->width)-- > 1)
		{
			write(1, " ", 1);
			val++;
		}
	}
	return (val);
}

int	ft_putchr(int i, t_info *info, int val)
{
	char	chr;

	chr = i;
	if (info->min == 1 && info->zero == 1)
		info->zero = 0;
	if (info->min == 1)
	{
		write(1, &chr, 1);
		val++;
		if (info->star == 1)
			val = chr_star(info, val);
	}
	else
	{
		if (info->star == 1)
			val = chr_star(info, val);
		write(1, &chr, 1);
		val++;
	}
	return (val);
}
