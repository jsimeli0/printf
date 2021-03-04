/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_ft_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 13:35:58 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/03/02 22:13:19 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include "../libft/ft_putchar_fd.c"
#include "../libft/ft_putint_fd.c"
#include "../libft/ft_putint_base_fd.c"
#include "../libft/ft_putstr_fd.c"
#include "../libft/ft_putuint_fd.c"
#include "../libft/ft_strlen.c"
#include "../libft/ft_atoi.c"
#include "../libft/ft_calloc.c"
#include "../libft/ft_isdigit.c"
#include "../libft/ft_itoa_base.c"
#include "../libft/ft_memcpy.c"
#include "../libft/ft_strjoin.c"
#include "../libft/ft_toupper.c"
#include "../libft/ft_bzero.c"
#include "../libft/ft_isspace.c"
#include "../libft/ft_strlcat.c"
#include "../libft/ft_strlcpy.c"
#include "../libft/ft_memset.c"
#include "../libft/ft_isalpha.c"
#include "../libft/ft_absolute.c"
#include "../libft/ft_strncmp.c"
#include "../srcs/ft_printf.c"
#include "../srcs/ft_printf_char_str.c"
#include "../srcs/ft_printf_flags.c"
#include "../srcs/ft_printf_int_uint.c"
#include "../srcs/ft_printf_ptr_hex.c"
#include "../srcs/ft_printf_specifier.c"
#include <limits.h>

int		main(void)
{
	FILE *fd;
	int res;

	/*
	** Printing positive numbers
	*/
	
	res = ft_printf("%u\n", (unsigned int)999);//1
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7u\n", (unsigned int)999);//2
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.7u\n", (unsigned int)12345);//3
	fprintf(fd, "%d\n", res);
	res = ft_printf("%.u\n", (unsigned int)12345);//4
	fprintf(fd, "%d\n", res);
	res = ft_printf("%010.u\n", (unsigned int)12345);//5
	fprintf(fd, "%d\n", res);
	res = ft_printf("%0.7u\n", (unsigned int)12345);//6
	fprintf(fd, "%d\n", res);

	res = ft_printf("%7.5u\n", (unsigned int)123);//7
	fprintf(fd, "%d\n", res);
	res = ft_printf("%7.2u\n", (unsigned int)123);//8
	fprintf(fd, "%d\n", res);
	res = ft_printf("%4.3u\n", (unsigned int)12345);//9
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3.4u\n", (unsigned int)12345);//10
	fprintf(fd, "%d\n", res);
	res = ft_printf("%6.7u\n", (unsigned int)12345);//11
	fprintf(fd, "%d\n", res);
	res = ft_printf("%2.7u\n", (unsigned int)12345);//12
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-7.5u\n", (unsigned int)123);//13
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-7.2u\n", (unsigned int)123);//14
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-4.3u\n", (unsigned int)12345);//15
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3.4u\n", (unsigned int)12345);//16
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-6.7u\n", (unsigned int)12345);//17
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-2.7u\n", (unsigned int)12345);//18
	fprintf(fd, "%d\n", res);

	res = ft_printf("%07.5u\n", (unsigned int)123);//19
	fprintf(fd, "%d\n", res);
	res = ft_printf("%07.2u\n", (unsigned int)123);//20
	fprintf(fd, "%d\n", res);
	res = ft_printf("%04.3u\n", (unsigned int)12345);//21
	fprintf(fd, "%d\n", res);
	res = ft_printf("%03.4u\n", (unsigned int)12345);//22
	fprintf(fd, "%d\n", res);
	res = ft_printf("%06.7u\n", (unsigned int)12345);//23
	fprintf(fd, "%d\n", res);
	res = ft_printf("%02.7u\n", (unsigned int)12345);//24
	fprintf(fd, "%d\n", res);

	/*
	** Print extreme values
	*/
	
	res = ft_printf("%15.5u\n", (unsigned int)3147483647);//25
	fprintf(fd, "%d\n", res);
	res = ft_printf("%15.15u\n", (unsigned int)3147483647);//26
	fprintf(fd, "%d\n", res);

	res = ft_printf("%-15.5u\n", (unsigned int)3147483647);//27
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-15.15u\n", (unsigned int)3147483647);//28
	fprintf(fd, "%d\n", res);
	
	res = ft_printf("%015.5u\n", (unsigned int)4294967295);//29
	fprintf(fd, "%d\n", res);
	res = ft_printf("%015.15u\n", (unsigned int)4294967295);//30
	fprintf(fd, "%d\n", res);

	return (0);
}
