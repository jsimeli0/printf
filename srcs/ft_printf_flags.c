/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_flags.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/03/02 16:12:17 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flags)
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

void	ft_parse_flags_precision(va_list ap, char **parse, t_flags *flags)
{
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
	if (flags->precision < 0)
		flags->precision = -1;
	if (flags->precision == 0)
		flags->zero = 0;
}

void	ft_set_width(char **parse, t_flags *flags)
{
	int	width;

	width = ft_atoi(*parse);
	if (width)
		flags->width = width;
	while (ft_isdigit(**parse))
		(*parse)++;
}

void	ft_parse_flags_width(va_list ap, char **parse, t_flags *flags)
{
	while (!ft_isalpha(**parse) && **parse != '.' && **parse != '%')
	{
		if (!ft_isdigit(**parse) || **parse == '0')
		{
			if (**parse == '0' && !flags->dash)
				flags->zero = 1;
			else if (**parse == '*')
			{
				flags->width = va_arg(ap, int);
				if (flags->width < 0)
				{
					flags->dash = 1;
					flags->zero = 0;
				}
				flags->width = ft_absolute(flags->width);
			}
			else if (**parse == '-')
			{
				flags->dash = 1;
				flags->zero = 0;
			}
			(*parse)++;
		}	
		ft_set_width(parse, flags);
	}
}

void	ft_parse_flags(va_list ap, char **parse, t_flags *flags)
{
	ft_parse_flags_width(ap, parse, flags);
	ft_parse_flags_precision(ap, parse, flags);
	flags->specifier = **parse;
	if (flags->width < flags->precision && flags->specifier != 's')
		flags->width = 0;
	if (flags->precision > 0 && (flags->specifier == 'd'
			|| flags->specifier == 'i' || flags->specifier == 'u'
			|| flags->specifier == 'X' || flags->specifier == 'x'))
		flags->zero = 0;
	(*parse)++;
}
