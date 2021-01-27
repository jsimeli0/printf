/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 10:04:17 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/25 23:41:48 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int		ft_absolute(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int		ft_size(int n, int base)
{
	int size;

	size = 1;
	while (n /= base)
		size++;
	return (size);
}

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	char	*arr;
	size_t	size;
	int		neg;

	if (base < 2 || base > 16)
		return (NULL);
	size = 0;
	neg = 0;
	arr = "0123456789abcdef";
	if (n < 0)
		neg = 1;
	n = ft_absolute(n);
	size = ft_size(n, base);
	str = malloc(sizeof(char) * (size + neg + 1));
	if (neg)
		str[0] = '-';
	while (n)
	{
		str[size + neg - 1] = arr[n % base];
		size--;
		n /= base;
	}
	return (str);
}

// int		main(void)
// {
// 	char	*str;
// 	int		n;

// 	n = -1120;
// 	str = ft_itoa_base(n, 10);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
