/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ptr_hex.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/03/02 16:12:29 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_save_ptr(va_list ap, t_flags *flags)
{
	long	ptr;
	char	*data;
	char	*data_temp;

	ptr = (unsigned long long)va_arg(ap, void *);
	if (ptr == 0 && flags->precision == 0)
		data = ft_strjoin("0x", "");
	else
	{
		data_temp = ft_itoa_base(ptr, 16);
		data = ft_strjoin("0x", data_temp);
		free(data_temp);
		data = ft_precision(data, flags);
	}
	return (data);
}

char	*ft_save_hex(va_list ap, t_flags *flags)
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
