/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char_str.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/03/02 19:28:37 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_save_str(va_list ap, t_flags *flags)
{
	char	*data_temp;
	char	*data;
	int		strlen;
	int		i;

	data_temp = va_arg(ap, char *);
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

char	*ft_save_char(va_list ap, t_flags *flags)
{
	char	*data;

	if (flags->specifier == '%')
		flags->character = '%';
	else
		flags->character = va_arg(ap, int);
	data = ft_calloc(2, sizeof(char));
	data[0] = flags->character;
	data = ft_precision(data, flags);
	return (data);
}
