/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/16 13:22:58 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbr_len(unsigned long long n, char x)
{
	unsigned long long	base;
	int					len;

	len = 0;
	if (x == 'x' || x == 'X' || x == 'p')
		base = 16;
	else
		base = 10;
	while (n >= base)
	{
		len++;
		n = n / base;
	}
	len++;
	return (len);
}

void	write_nbr(unsigned long long n, char x, unsigned int base)
{
	if (n >= base)
	{
		write_nbr(n / base, x, base);
		write_nbr(n % base, x, base);
	}
	else
	{
		if (x == 'x' || x == 'p')
			write(1, &"0123456789abcdef"[n % base], 1);
		else if (x == 'X')
			write(1, &"0123456789ABCDEF"[n % base], 1);
		else if (x == 'd' || x == 'i' || x == 'u')
			write(1, &"0123456789"[n % base], 1);
	}
}

int		ft_isnum(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int		ft_strlen(const char *s)
{
	unsigned int	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}
