/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_specifier.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/03/02 23:42:29 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision(char *data, t_flags *flags)
{
	int		strlen;
	int		i;
	char	*zeroes;
	char	*data_return;

	if (flags->precision == -1)
		return (data);
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
	zeroes = ft_calloc(flags->precision - strlen + 1, sizeof(char));
	ft_memset(zeroes, '0', flags->precision - strlen);
	data_return = ft_strjoin(zeroes, data);
	free(data);
	return (data_return);
}

char	*ft_data(va_list ap, t_flags *flags)
{
	char	*data;

	data = NULL;
	if (flags->specifier == 's')
		data = ft_save_str(ap, flags);
	else if (flags->specifier == 'd' || flags->specifier == 'i')
		data = ft_save_int(ap, flags);
	else if (flags->specifier == 'c' || flags->specifier == '%')
		data = ft_save_char(ap, flags);
	else if (flags->specifier == 'p')
		data = ft_save_ptr(ap, flags);
	else if (flags->specifier == 'u')
		data = ft_save_uint(ap, flags);
	else if (flags->specifier == 'x' || flags->specifier == 'X')
		data = ft_save_hex(ap, flags);
	return (data);
}

char	*ft_field(t_flags *flags)
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

void	ft_specifier_init(t_specifier *spec, va_list ap, t_flags *flags)
{
	spec->field = ft_field(flags);
	spec->field_len = ft_strlen(spec->field);
	spec->data = ft_data(ap, flags);
	spec->data_len = ft_strlen(spec->data);
}

void	ft_specifier(va_list ap, t_flags *flags, size_t *char_count)
{
	t_specifier	spec;

	ft_specifier_init(&spec, ap, flags);
	if (flags->character == '\0')
		spec.data_len = 1;
	spec.offset = spec.field_len - spec.data_len;
	if ((spec.offset) < 0)
	{
		ft_putstr_fd(spec.data, 1, spec.data_len);
		*char_count += spec.data_len;
	}
	else
	{
		if (!flags->dash)
			ft_memcpy(spec.field + spec.offset, spec.data, spec.data_len);
		else
			ft_memcpy(spec.field, spec.data, spec.data_len);
		if (flags->sign == -1 && flags->zero && (flags->specifier == 'd'\
		 || flags->specifier == 'i'))
			ft_putsign(spec.field);
		*char_count += spec.field_len;
		ft_putstr_fd(spec.field, 1, spec.field_len);
	}
	free(spec.field);
	free(spec.data);
}
