/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/23 23:47:56 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include "../libft/libft.h"
#include "../libft/ft_putchar_fd.c"
#include "../libft/ft_putint_fd.c"
#include "../libft/ft_putint_base_fd.c"
#include "../libft/ft_putstr_fd.c"
#include "../libft/ft_putuint_fd.c"
#include "../libft/ft_strlen.c"

int			main(void)
{
	int		num = -1;
	int		hex = 8123;
	// int		num2 = 500;
	char	*str = "Hello";
	// char	*str2 = "Bye";
	char 	c = '9';

	ft_printf("ft_printf:\nint: %d, string: %s, char: %c, unsigned int: %u, hex: %x, HEX: %X\n", num, str, c, num, hex, hex);
	printf("printf:\nint: %d, string: %s, char: %c, unsigned int: %u, hex: %x, HEX: %X\n", num, str, c, num, hex, hex);
	return (0);
}

void		ft_print_int(va_list ap, t_flags *flags, int *char_count)
{
		int	n;

		n = va_arg (ap, int);
		ft_putint_fd(n, 1);
}

// This is still printing as a negative sign... why?
void		ft_print_uint(va_list ap, t_flags *flags, int *char_count)
{
		unsigned int	n;

		n = va_arg (ap, unsigned int);
		ft_putuint_fd(n, 1);
}

void		ft_print_str(va_list ap, t_flags *flags, int *char_count)
{
		char *str;

		str = va_arg (ap, char*);
		ft_putstr_fd(str, 1);
}

void		ft_print_char(va_list ap, t_flags *flags, int *char_count)
{
		char c;

		c = va_arg (ap, int);
		ft_putchar_fd(c, 1);
}

void		ft_print_hexlow(va_list ap, t_flags *flags, int *char_count)
{
		char	*base;
		int		c;

		base = "0123456789abcdef";
		c = va_arg (ap, int);
		ft_putint_base_fd(c, base, 1);
}

void		ft_print_hexup(va_list ap, t_flags *flags, int *char_count)
{
		char	*base;
		int		c;

		base = "0123456789ABCDEF";
		c = va_arg (ap, int);
		ft_putint_base_fd(c, base, 1);
}

/* To be implemented */
// void	ft_parse_ptr(va_list ap);

// Floating point only for bonus
// void	ft_parse_float(va_list ap);


void		ft_walk(char **parse, int *char_count)
{
	while (**parse && **parse != '%')
	{
		ft_putchar_fd(**parse, 1);
		(*parse)++;
		(*char_count)++;
	}
}

static void	ft_parse_flags(va_list ap, char **parse, t_flags *flags)
{
	(*parse++);
	
}

static void	ft_modifier(va_list ap, t_flags *flags, int *char_count)
{
	/* All of these functions' declarations have to be fixed to not include parse */

	if (flags->modifier == 's')
		ft_print_str(ap, flags, char_count);
	else if (flags->modifier == 'd' || flags->modifier == 'i')
		ft_print_int(ap, flags, char_count);
	else if (flags->modifier == 'c')
		ft_print_char(ap, flags, char_count);
	else if (flags->modifier == 'u')
		ft_print_uint(ap, flags, char_count);
	else if (flags->modifier == 'x')
		ft_print_hexlow(ap, flags, char_count);
	else if (flags->modifier == 'X')
		ft_print_hexup(ap, flags, char_count);
	else if (flags->modifier == '%')
		ft_putchar_fd('%', 1);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*parse;
	t_flags	flags;
	size_t	char_count; 

	char_count = 0;
	parse = (char*)str;
	va_start(ap, str);
	// ft_walk((char*)str, ap, &char_count);
	while (*parse)
	{
		ft_walk(&parse, &char_count);
		if (*parse != '%')
			break;
		ft_parse_flags(ap, &parse, &flags);
		ft_modifier(ap, &flags, char_count);
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
