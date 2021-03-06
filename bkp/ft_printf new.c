/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/28 21:53:13 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_walk(char **parse, size_t *char_count)
{
	while (**parse)
	{
		if (**parse != '%')
		{
			ft_putchar_fd(**parse, 1);
			(*char_count)++;
			(*parse)++;
		}
		else
		{
			(*parse)++;
			break ;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*parse;
	t_flags	flags;
	size_t	char_count;

	if (!str)
		return (0);
	char_count = 0;
	parse = (char *)str;
	va_start(ap, str);
	while (*parse)
	{
		ft_walk(&parse, &char_count);
		if (*parse != '%')
			break ;
		ft_parse_flags(ap, &parse, &flags);
		ft_specifier(ap, &flags, &char_count);
	}
	va_end(ap);
	return (char_count);
}
