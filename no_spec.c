/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/18 19:11:52 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_spec(t_info *info, int val)
{
	if (info->min == 1)
		return (val);
	else if (info->zero == 1)
	{
		while (info->width-- > 1)
		{
			write(1, "0", 1);
			val++;
		}
	}
	else
		while (info->width-- > 1)
		{
			write(1, " ", 1);
			val++;
		}
	return (val);
}
