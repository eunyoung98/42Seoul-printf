# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehwangbo <ehwangbo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 12:04:42 by ehwangbo          #+#    #+#              #
#    Updated: 2021/06/16 13:28:08 by ehwangbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c\
			ft_str.c\
			print_address.c\
			print_chr.c\
			print_str.c\
			print_dechex.c\
			print_flag.c\
			no_spec.c\
			set_dec.c\
			set_info.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

ARFLAGS	= rcs

RM		= rm -f

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $<

$(NAME)	:	$(OBJS)
			ar $(ARFLAGS) $@ $^

clean	:
			$(RM) $(OBJS) 

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.phony	:	re	fclean	all	clean
