/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/25 16:42:31 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include "../libft/libft.h"
// #include "../libft/ft_putchar_fd.c"
// #include "../libft/ft_putint_fd.c"
// #include "../libft/ft_putint_base_fd.c"
// #include "../libft/ft_putstr_fd.c"
// #include "../libft/ft_putuint_fd.c"
// #include "../libft/ft_strlen.c"
// #include "../libft/ft_atoi.c"
// #include "../libft/ft_calloc.c"
// #include "../libft/ft_isdigit.c"
// #include "../libft/ft_itoa_base.c"
// #include "../libft/ft_memcpy.c"
// #include "../libft/ft_strjoin.c"
// #include "../libft/ft_toupper.c"
// #include "../libft/ft_bzero.c"
// #include "../libft/ft_isspace.c"
// #include "../libft/ft_strlcat.c"
// #include "../libft/ft_strlcpy.c"
// #include "../libft/ft_memset.c"
// #include "../libft/ft_isalpha.c"
// #include "../libft/ft_absolute.c"
// #include "../libft/ft_strncmp.c"
// #include <limits.h>

// // int			main(void)
// // {
// // 	int		a = 4;
// // 	int		b = 14;
// // 	char	c = 'a';
// // 	int		d = 2147483647;
// // 	int		e = -2147483648;
// // 	int		f = 42;
// // 	int		g = 25;
// // 	int		h = 4200;
// // 	int		i = 8;
// // 	int		j = -12;
// // 	int		k = 123456789;
// // 	int		l = 0;
// // 	int		m = -12345678;
// // 	char	*n = "abcdefghijklmnop";
// // 	char	*o = "-a";
// // 	char	*p = "-12";
// // 	char	*q = "0";
// // 	char	*r = "%%";
// // 	char	*s = "-2147483648";
// // 	char	*t = "0x12345678";
// // 	char	*u = "-0";

// // 	ft_printf(" --- Return : %d\n", ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
// // 	ft_printf(" --- Return : %d\n", ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
// // 	ft_printf(" --- Return : %d\n", ft_printf("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
// // 	ft_printf(" --- Return : %d\n", ft_printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));

// // 	return (0);
// // }

// int main()
// {
// 	int		a = -4;
// 	int		b = 0;
// 	char	c = 'a';
// 	int		d = 2147483647;
// 	int		e = -2147483648;
// 	int		f = 42;
// 	int		g = 25;
// 	int		h = 4200;
// 	int		i = 8;
// 	int		j = -12;
// 	int		k = 123456789;
// 	int		l = 0;
// 	int		m = -12345678;
// 	char	*n = "abcdefghijklmnop";
// 	char	*o = "-a";
// 	char	*p = "-12";
// 	char	*q = "0";
// 	char	*r = "%%";
// 	char	*s = "-2147483648";
// 	char	*t = "0x12345678";
// 	char	*u = "-0";

// 	// ft_printf(" --- Return : %d\n", ft_printf("Simple input test"));

// 	// ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
// 	// printf(" --- Return : %d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2

// 	// ft_printf(" --- Return : %d\n", ft_printf("%0*.*d", 1, 3, 0)); //T141
// 	// printf(" --- Return : %d\n", printf("%0*.*d", 1, 3, 0)); //T141

// 	// ft_printf(" --- Return : %d\n", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0)); //T510
// 	// printf(" --- Return : %d\n", printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0)); //T510

// 	// a = 12;
// 	// b = 18;
// 	// ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
// 	// printf(" --- Return : %d\n", printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));

// 	ft_printf(" --- Return : %d\n", ft_printf("%-3c", 0));
// 	printf("\n");
// 	printf(" --- Return : %d\n", printf("%-3c", 0));
// 	printf("\n");

// 	// ft_printf(" --- Return : %d\n", ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d)); //T3
// 	// ft_printf(" --- Return : %d\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d)); //T4
// 	// ft_printf(" --- Return : %d\n", ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d)); //T5
// 	// ft_printf(" --- Return : %d\n", ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
// 	// ft_printf(" --- Return : %d\n", ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
// 	// ft_printf(" --- Return : %d\n", ft_printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d)); //T8
// 	// ft_printf(" --- Return : %d\n", ft_printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d)); //T9
// 	// ft_printf(" --- Return : %d\n", ft_printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d)); //T10
// 	// ft_printf(" --- Return : %d\n", ft_printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d)); //T11
// 	// ft_printf(" --- Return : %d\n", ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d)); //T12
// 	// ft_printf(" --- Return : %d\n", ft_printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c, e, d)); //T13
// 	// ft_printf(" --- Return : %d\n", ft_printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d)); //T14
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T15
// 	// ft_printf(" --- Return : %d\n", ft_printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d)); //T16
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d)); //T17
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d)); //T18
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d)); //T19
// 	// ft_printf(" --- Return : %d\n", ft_printf("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c, e, d)); //T20
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c, e, d)); //T21
// 	// ft_printf(" --- Return : %d\n", ft_printf("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c, e, d)); //T22
// 	// ft_printf(" --- Return : %d\n", ft_printf("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d)); //T23
	
// 	// ft_printf(" --- Return : %d\n", ft_printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d)); //T24
// 	// printf(" --- Return : %d\n", printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d)); //T24
	
// 	// ft_printf(" --- Return : %d\n", ft_printf("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c, e, d)); //T25
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T26
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c, e, d)); //T27
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T28
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c, e, d)); //T29
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d)); //T30
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d)); //T31
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d)); //T32
// 	// ft_printf(" --- Return : %d\n", ft_printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d)); //T33
// 	// while (a < 5) //T34-69
// 	// {
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
// 	// 	a++;
// 	// }

// 	// int z = 70;
// 	// a = -2;
// 	// while(a < 5) //T70-177
// 	// {
// 	// 	printf("Test %d:\n", z);
// 	// 	b = -2;
// 	// 	while (b < 5)
// 	// 	{
// 	// 		ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
// 	// 		ft_printf(" --- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
// 	// 		ft_printf(" --- Return : %d\n", ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
// 	// 		b++;
// 	// 		z++;
// 	// 	}
// 	// 	a++;
// 	// }



// 	// a = 19;
// 	// b = 14;
// 	// // ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42)); //T178
// 	// // ft_printf(" --- Return : %d\n", ft_printf("%12.12i, %12.12d", -42, 42)); //T179
// 	// // ft_printf(" --- Return : %d\n", ft_printf("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T180
// 	// // ft_printf(" --- Return : %d\n", ft_printf("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T181
// 	// // // ft_printf(" --- Return : %d\n", ft_printf("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T182
// 	// // // ft_printf(" --- Return : %d\n", ft_printf("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T183
// 	// // // ft_printf(" --- Return : %d\n", ft_printf("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T184
// 	// // ft_printf(" --- Return : %d\n", ft_printf("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T185
// 	// // ft_printf(" --- Return : %d\n", ft_printf("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r)); //T186
// 	// // ft_printf(" --- Return : %d\n", ft_printf("%.s, %.s, %.s, %.s, %.s", n, o, p, q, r)); //T186
// 	// // ft_printf(" --- Return : %d\n", ft_printf("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r)); //T186
// 	// a = -4;
// 	// while (a < 5) //T187-213
// 	// {
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u));
// 	// 	a++;
// 	// }

// 	// a = -2;
// 	// while(a < 5) //T70-177
// 	// {
// 	// 	b = -2;
// 	// 	while (b < 5)
// 	// 	{
// 	// 		ft_printf(" --- Return : %d\n", ft_printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
// 	// 		ft_printf(" --- Return : %d\n", ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
// 	// 		b++;
// 	// 	}
// 	// 	a++;
// 	// }

// 	// ft_printf(" --- Return : %d\n", ft_printf("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T214
// 	// a = -1;
// 	// while (a < 5) //T214-256
// 	// {
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
// 	// 	a++;
// 	// }
// 	// a = -1;
// 	// while(a < 5) //T257-346
// 	// {
// 	// 	b = -1;
// 	// 	while (b < 5)
// 	// 	{
// 	// 		ft_printf(" --- Return : %d\n", ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
// 	// 		ft_printf(" --- Return : %d\n", ft_printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
// 	// 		ft_printf(" --- Return : %d\n", ft_printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
// 	// 		b++;
// 	// 	}
// 	// 	a++;
// 	// }
// 	// ft_printf(" --- Return : %d\n", ft_printf("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0)); //T347
// 	// a = 8;
// 	// while (a < 12) //
// 	// {
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
// 	// 	ft_printf(" --- Return : %d\n", ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));
// 	// 	a++;
// 	// }
// 	// a = f;
// 	// b = g;
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));

// 	// a = 12;
// 	// b = 18;
// 	// ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%%, \t, \\, \", \', +"));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
// 	// ft_printf(" --- Return : %d\n", ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
// 	// // ^ Theoriquement un comportement indefini mais testé par la moulinette
//     // ft_printf(" --- Return : %d\n", ft_printf("(null)"));
// 	// ft_printf(" --- Return : %d\n", ft_printf(""));
// }

char		*ft_precision(char *data, t_flags *flags)
{
	int		strlen;
	int		i;
	char	*zeroes;
	char	*data_return;

	strlen = ft_strlen(data);
	if (flags->precision <= strlen)
	{
		if (flags->specifier == 's')
			data[flags->precision] = 0;
		return (data);
	}
	if (flags->specifier == 's')
		return (data);
	i = 0;
	zeroes = ft_calloc(flags->precision - strlen, sizeof(char));  // strlen - flags sometimes evaluates to negative
	while (i < flags->precision - strlen)
	{
		zeroes[i] = '0';
		i++;
	}
	data_return = ft_strjoin(zeroes, data);
	free(data);
	return (data_return);
}

char		*ft_save_int(va_list ap, t_flags *flags)
{
	long int	n;
	char			*data;
	char			*data_temp;

	n = va_arg(ap, int);
	if (n < 0)
		flags->sign = -1;
	n = ft_absolute(n);
	if (n == 0 && flags->precision == 0)
	{
		data = ft_calloc(1, sizeof(char));
		return (data);
	}
	data = ft_itoa_base(n, 10);
	data = ft_precision(data, flags);  // problem might be here
	if (flags->sign == -1)
	{
		data_temp = ft_strjoin("-", data);
		free(data);
		data = data_temp;
	}
	return (data);
}

// This is still printing as a negative sign... why?
char		*ft_save_uint(va_list ap, t_flags *flags)
{
	unsigned int	n;
	char			*data;

	n = va_arg(ap, unsigned int);
	if (n == 0 && flags->precision == 0)
	{
		data = ft_calloc(1, sizeof(char));
		return (data);
	}
	data = ft_itoa_base(n, 10);
	data = ft_precision(data, flags);
	return (data);
}

char		*ft_save_ptr(va_list ap, t_flags *flags)
{
	long	ptr;
	char	*data;
	char	*data_temp;

	ptr = (unsigned long long)va_arg(ap, void *);
	data_temp = ft_itoa_base(ptr, 16);
	data = ft_strjoin("0x", data_temp);
	free(data_temp);
	data = ft_precision(data, flags);
	return (data);
}

char		*ft_save_hex(va_list ap, t_flags *flags)
{
	unsigned int		n;
	char				*data;
	int					i;
	int					strlen;

	n = va_arg(ap, unsigned int);
	if (n == 0 && flags->precision == 0)
	{
		data = ft_calloc(1, sizeof(char));
		return (data);
	}
	data = ft_itoa_base(n, 16);
	if (flags->specifier == 'X')
	{
		strlen = ft_strlen(data);
		i = 0;
		while (i < strlen)
		{
			data[i] = ft_toupper(data[i]);
			i++;
		}
	}
	data = ft_precision(data, flags);
	return (data);
}

char		*ft_save_str(va_list ap, t_flags *flags)
{
	char	*data_temp;
	char	*data;
	int		strlen;
	int		i;

	data_temp = va_arg(ap, char*);
	if (!data_temp)
	{
		if (!flags->precision)
			data_temp = "";
		else
			data_temp = "(null)";
	}
	strlen = ft_strlen(data_temp);
	data = ft_calloc(strlen + 1, sizeof(char));
	i = 0;
	while (i < strlen)
	{
		data[i] = data_temp[i];
		i++;
	}
	data = ft_precision(data, flags);
	return (data);
}

char		*ft_save_char(va_list ap, t_flags *flags)
{
	char	*data;

	if (flags->specifier == '%')
		flags->character = '%';
	else
		flags->character = va_arg(ap, int);
	data = ft_calloc(2 , sizeof(char));
	data[0] = flags->character;
	data = ft_precision(data, flags);
	return (data);
}

/* To be implemented */
// void	ft_parse_ptr(va_list ap);

// Floating point only for bonus
// void	ft_parse_float(va_list ap);

void		ft_walk(char **parse, size_t *char_count)
{
	while (**parse && **parse != '%')
	{
		ft_putchar_fd(**parse, 1);
		(*parse)++;
		(*char_count)++;
	}
}

void		ft_init_flags(t_flags *flags)
{
	flags->specifier = 0;
	flags->width = 0;
	flags->dash = 0;
	flags->precision = -1;
	flags->zero = 0;
	flags->star = 0;
	flags->sign = 0;
	flags->character = -100;
}

// void		ft_asterisk(va_list ap, char **parse, t_flags *flags)
// {
	
// }

void		ft_parse_flags(va_list ap, char **parse, t_flags *flags)
{
	int	width;

	(*parse)++;			// Check if parenthesis is necesary
	ft_init_flags(flags);
	while (!ft_isalpha(**parse) && **parse != '.' && **parse != '%')
	{
		if (**parse == '0' && !flags->dash)
		{
			flags->zero = 1;
			(*parse)++;
		}
		if (**parse == '*')
		{
			flags->width = va_arg(ap, int);
			if (flags->width < 0)
			{
				flags->dash = 1;
				flags->zero = 0;
			}
			flags->width = ft_absolute(flags->width);
			(*parse)++;
		}
		if (**parse == '-')
		{
			flags->dash = 1;
			flags->zero = 0;
			(*parse)++;
		}
		if ((width = ft_atoi(*parse)))
			flags->width = width;
		while (ft_isdigit(**parse))
			(*parse)++;
	}
	if (**parse == '.')
	{
		(*parse)++;
		if (**parse == '*')
		{
			flags->precision = va_arg(ap, int);
			if (flags->precision == 0)
				flags->zero = 0;
			(*parse)++;
		}
		else
		{
			flags->precision = ft_atoi(*parse);
			while (ft_isdigit(**parse))
				(*parse)++;
		}
	}
	// if (**parse == '%')
	// 	flags->specifier = '%';
	flags->specifier = **parse;	//This step will always be last
	if (flags->width < flags->precision && flags->specifier != 's')
		flags->width = 0;
	if (flags->precision > 0 && (flags->specifier == 'd' || flags->specifier == 'i' || flags->specifier == 'u' || flags->specifier == 'X' || flags->specifier == 'x'))
		flags->zero = 0;
	(*parse)++;
}

char		*ft_field(t_flags *flags)
{
	char	*str;
	char	c;
	int		i;

	str = ft_calloc(flags->width + 1, sizeof(char));
	c = ' ';
	if (flags->zero)
		c = '0';
	i = 0;
	while (i < flags->width)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

char		*ft_data(va_list ap, t_flags *flags)
{
	char	*data;

	data = NULL;
	if (flags->specifier == 's')
		data = ft_save_str(ap, flags);				// Rewrite this function 
	else if (flags->specifier == 'd' || flags->specifier == 'i')
		data = ft_save_int(ap, flags);
	else if (flags->specifier == 'c' || flags->specifier == '%')				// Rewrite this function 
		data = ft_save_char(ap, flags);
	else if (flags->specifier == 'p')				// Rewrite this function 
		data = ft_save_ptr(ap, flags);
	else if (flags->specifier == 'u')				// Rewrite this function 
		data = ft_save_uint(ap, flags);
	else if (flags->specifier == 'x' || flags->specifier == 'X')				// Rewrite this function 
		data = ft_save_hex(ap, flags);
	return (data);
}

void		ft_putsign(char *field)
{
	*field = '-';
	field++;
	while(*field != '-')
		field++;
	*field = '0';
}

void		ft_specifier(va_list ap, t_flags *flags, size_t *char_count)
{
	char	*field;
	char	*data;
	int		field_len;
	int		data_len;
	int		offset;

	field = ft_field(flags);		// Corner case where you get spaces before AND after specifier?? Ie "%-5.4d", 123. Output will be "0123 ""
	field_len = ft_strlen(field);
	data = ft_data(ap, flags);
	data_len = ft_strlen(data);
	if (flags->character == '\0')
	{
		data_len = 1;
		// (*char_count)++;
	}
	offset = field_len - data_len;
	if (offset < 0)
	{
		ft_putstr_fd(data, 1, data_len);
		*char_count += data_len;
	}
	else
	{
		if (!flags->dash)
			ft_memcpy(field + offset, data, data_len);
		else
			ft_memcpy(field, data, data_len);
		if (flags->sign == -1 && flags->zero && (flags->specifier == 'd' || flags->specifier == 'i'))
			ft_putsign(field);
		*char_count += field_len;
		ft_putstr_fd(field, 1, field_len);
	}
	free(field);
	free(data);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*parse;
	t_flags	flags;
	size_t	char_count; 

	if (!str)
		return (0);
	char_count = 0;
	parse = (char*)str;
	va_start(ap, str);
	while (*parse)
	{
		ft_walk(&parse, &char_count);
		if (*parse != '%')
			break;
		ft_parse_flags(ap, &parse, &flags);
		ft_specifier(ap, &flags, &char_count);
	}
	va_end(ap);
	return (char_count);
}

// Questions that arise:
// 	1. can you pass ap to another function? what happens when you updated it? Do you have to pass it by pointer? line 42

/* Mechanics of parsing input:
1. First argument is always a string.
2. Start writing the string with putchar
3. If you encounter a %d, call a function that writes the next argument in argv;
 */
