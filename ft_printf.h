/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:21:50 by ehwangbo          #+#    #+#             */
/*   Updated: 2021/06/16 13:26:24 by ehwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_info
{
	int		min;
	int		zero;
	int		star;
	int		width;
	int		dot;
	int		prec;
	int		nbr_minus;
	char	type;
}				t_info;

int				no_spec(t_info *info, int val);

int				chk_type(va_list ap, t_info *info, int val);
int				chk_flag(char *format, t_info *info, va_list ap, int i);
int				chk_format(va_list ap, char *format, int val, t_info *info);
int				chk_loop(char format);
int				ft_printf(const char *format, ...);

void			init_info(t_info *info);
int				set_type(char *format, t_info *info, int i);
int				set_width(char *format, t_info *info, va_list ap, int i);
int				set_prec(char *format, t_info *info, va_list ap, int i);

int				nbr_len(unsigned long long n, char x);
void			write_nbr(unsigned long long n, char x, unsigned int base);
int				ft_isnum(int c);
int				ft_strchr(char *s, int c);
int				ft_strlen(const char *s);

int				address_star(t_info *info, unsigned long long num, int val);
int				address_left(t_info *info, unsigned long long num, int val);
int				address_right(t_info *info, unsigned long long num, int val);
int				ft_putaddress(t_info *info, unsigned long long num, int val);

int				chr_star(t_info *info, int val);
int				ft_putchr(int i, t_info *info, int val);

int				str_star(char *s, t_info *info, int val);
int				str_zero(char *s, t_info *info, int val);
int				is_str(char *s, t_info *info, int val);
int				str_null(t_info *info, int val);
int				ft_putstr(char *s, t_info *info, int val);

void			print_nbr(unsigned int num, char x);
int				chk_minus(t_info *info, int val);
int				min_int(t_info *info, int val);
int				ft_putnbr_fd(int n, t_info *info, int val);

int				print_star(unsigned int num, t_info *info, int val);
int				print_zero(unsigned int num, t_info *info, int val);

int				print_left(unsigned int num, t_info *info, int val);
int				print_right(unsigned int num, t_info *info, int val);
int				no_dot(unsigned int num, t_info *info, int val);
int				is_dechex_dot(unsigned int num, t_info *info, int val);
int				print_dechex(t_info *info, unsigned int num, int val);

#endif
