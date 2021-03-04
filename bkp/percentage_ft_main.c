/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   percentage_ft_main.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 11:44:24 by hyilmaz       #+#    #+#                 */
/*   Updated: 2021/03/02 22:10:51 by jsimelio      ########   odam.nl         */
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
	int i;
	FILE *fd;
	int res;

	i = 0;
	
    res = ft_printf("%%\n");//1
	fprintf(fd, "%d\n", res);
    res = ft_printf("%1%\n");//2
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-1%\n");//3
	fprintf(fd, "%d\n", res);
	res = ft_printf("%3%\n");//4
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-3%\n");//5
	fprintf(fd, "%d\n", res);
	res = ft_printf("%5%\n");//6
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-5%\n");//7
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*%\n", 4);//8
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*%\n", 4);//9
	fprintf(fd, "%d\n", res);
	res = ft_printf("%*%\n", 0);//10
	fprintf(fd, "%d\n", res);
	res = ft_printf("%-*%\n", 0);//11
	fprintf(fd, "%d\n", res);

    return (0);
}
