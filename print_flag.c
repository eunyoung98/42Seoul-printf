/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/18 13:46:21 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zero(unsigned int num, t_info *info, int val)
{
	int	temp;

	if (info->dot == 1)
	{
		temp = info->prec - nbr_len(num, info->type);
		while (temp-- > 0)
		{
			write(1, "0", 1);
			info->width--;
			val++;
		}
	}
	else
	{
		while ((info->width)-- > nbr_len(num, info->type) + info->nbr_minus)
		{
			write(1, "0", 1);
			val++;
		}
	}
	return (val);
}

int	print_star(unsigned int num, t_info *info, int val)
{
	if (info->dot == 1 && info->prec > nbr_len(num, info->type))
	{
		while ((info->width)-- > info->prec + info->nbr_minus)
		{
			write(1, " ", 1);
			val++;
		}
	}
	else
	{
		while ((info->width)-- > nbr_len(num, info->type) + info->nbr_minus)
		{
			write(1, " ", 1);
			val++;
		}
	}
	return (val);
}
