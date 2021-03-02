/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_int_uint.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/03/02 16:12:22 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_save_int(va_list ap, t_flags *flags)
{
	long int	n;
	char		*data;
	char		*data_temp;

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
	data = ft_precision(data, flags);
	if (flags->sign == -1)
	{
		data_temp = ft_strjoin("-", data);
		free(data);
		data = data_temp;
	}
	return (data);
}

char	*ft_save_uint(va_list ap, t_flags *flags)
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
