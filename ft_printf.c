/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/11/30 18:47:12 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int		num = 300;
	int		num2 = 500;
	char	*str = "Hello/n";
	char	*str2 = "Bye";

	ft_printf("Hello! %c?");
	return (0);
}

void	ft_parse(const char **str, va_list ap)
{
	**str++;
	if (**str == 's')

}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			ft_parse(&str, ap);
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	return (0);
}

// Questions that arise:
// 	1. can you pass ap to another function? what happens when you updated it? Do you have to pass it by pointer? line 42

/* Mechanics of parsing input:
1. First argument is always a string.
2. Start writing the string with putchar
3. If you encounter a %d, call a function that writes the next argument in argv;
 */
