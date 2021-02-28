/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 10:04:17 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/28 23:46:44 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_size(long long int n, int base)
{
	int	size;

	size = 1;
	n /= base;
	while (n)
	{
		n /= base;
		size++;
	}
	return (size);
}

char	*ft_write_string(long long int n, int base, int neg)
{
	size_t	size;
	char	*arr;
	char	*str;

	arr = "0123456789abcdef";
	n = ft_absolute(n);
	size = ft_size(n, base);
	str = ft_calloc(size + neg + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (neg)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[size + neg - 1] = arr[n % base];
		size--;
		n /= base;
	}
	return (str);
}

char	*ft_itoa_base(long long int n, int base)
{
	char	*str;
	int		neg;

	if (base < 2 || base > 16)
		return (NULL);
	neg = 0;
	if (n < 0)
		neg = 1;
	str = ft_write_string(n, base, neg);
	if (!str)
		return (NULL);
	return (str);
}
