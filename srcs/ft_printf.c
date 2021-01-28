/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 16:57:34 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/28 14:47:31 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include "../libft/libft.h"
// #include "../libft/ft_putchar_fd.c"
// #include "../libft/ft_putint_fd.c"
// #include "../libft/ft_putint_base_fd.c"
// #include "../libft/ft_putstr_fd.c"
// #include "../libft/ft_putuint_fd.c"
// #include "../libft/ft_strlen.c"
// #include "../libft/ft_atoi.c"
// #include "../libft/ft_calloc.c"
// #include "../libft/ft_isdigit.c"
// #include "../libft/ft_itoa_base.c"
// #include "../libft/ft_memcpy.c"
// #include "../libft/ft_strjoin.c"
// #include "../libft/ft_toupper.c"
// #include "../libft/ft_bzero.c"
// #include "../libft/ft_isspace.c"
// #include "../libft/ft_strlcat.c"
// #include "../libft/ft_strlcpy.c"
// #include "../libft/ft_memset.c"
// #include "../libft/ft_isalpha.c"

// int			main(void)
// {
// 	// int		num = -1;
// 	// int		hex = 8123;
// 	// // int		num2 = 500;
// 	// char	*str = "Hello";
// 	// // char	*str2 = "Bye";
// 	// char 	c = '9';
// 	// char	*printstr = "%-6.20d a\n";
	
// 	ft_printf("-%05.4d-\n", 123);
// 	printf("-%05.4d-\n", 123);

// 	// printf(printstr, 100000);

// 	// ft_printf("ft_printf:\nint: %d, string: %s, char: %c, unsigned int: %u, hex: %x, HEX: %X\n", num, str, c, num, hex, hex);
// 	// printf("printf:\nint: %d, string: %s, char: %c, unsigned int: %u, hex: %x, HEX: %X\n", num, str, c, num, hex, hex);
// 	return (0);
// }

char		*ft_precision(char *data, t_flags *flags)
{
	int		strlen;
	int		i;
	char	*zeroes;
	char	*data_return;

	strlen = ft_strlen(data);
	if (flags->precision < strlen)
		return (data);
	i = 0;
	zeroes = ft_calloc(flags->precision - strlen, sizeof(char));  // strlen - flags sometimes evaluates to negative
	while (i < flags->precision - strlen)
	{
		zeroes[i] = '0';
		i++;
	}
	data_return = ft_strjoin(zeroes, data);
	free(data);
	return (data_return);
}

char		*ft_save_int(va_list ap, t_flags *flags)
{
	int				n;
	char			*data;

	n = va_arg (ap, int);
	data = ft_itoa_base(n, 10);
	data = ft_precision(data, flags);
	return (data);
}

// This is still printing as a negative sign... why?
char		*ft_save_uint(va_list ap, t_flags *flags)
{
	unsigned int	n;
	char			*data;

	n = va_arg (ap, unsigned int);
	data = ft_itoa_base(n, 10);
	data = ft_precision(data, flags);
	return (data);
}

char		*ft_save_ptr(va_list ap, t_flags *flags)
{
	unsigned long long	ptr;
	char				*data;
	char				*data_temp;

	ptr = (unsigned long long)va_arg (ap, void *);
	data_temp = ft_itoa_base(ptr, 16);
	data = ft_strjoin("0x", data_temp);
	free(data_temp);
	data = ft_precision(data, flags);
	return (data);
}

char		*ft_save_hex(va_list ap, t_flags *flags)
{
	int		n;
	char	*data;
	int		i;
	int		strlen;

	n = va_arg (ap, int);
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

char		*ft_save_str(va_list ap, t_flags *flags)
{
	char	*data_temp;
	char	*data;
	int		strlen;
	int		i;

	data_temp = va_arg (ap, char*);
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

char		*ft_save_char(va_list ap, t_flags *flags)
{
	char 	c;
	char	*data;

	if (flags->specifier == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	data = ft_calloc(2 , sizeof(char));
	data[0] = c;
	data = ft_precision(data, flags);
	return (data);
}

/* To be implemented */
// void	ft_parse_ptr(va_list ap);

// Floating point only for bonus
// void	ft_parse_float(va_list ap);

void		ft_walk(char **parse, size_t *char_count)
{
	while (**parse && **parse != '%')
	{
		ft_putchar_fd(**parse, 1);
		(*parse)++;
		(*char_count)++;
	}
}

void		ft_init_flags(t_flags *flags)
{
	flags->specifier = 0;
	flags->width = 0;
	flags->dash = 0;
	flags->precision = 0;
	flags->zero = 0;
	flags->star = 0;
}

void		ft_parse_flags(char **parse, t_flags *flags)
{
	int	width;

	(*parse)++;			// Check if parenthesis is necesary
	ft_init_flags(flags);
	while (!ft_isalpha(**parse) && **parse != '.')
	{
		if (**parse == '0' && !flags->dash)
		{
			flags->zero = 1;
			(*parse)++;
		}
		if (**parse == '-')
		{
			flags->dash = 1;
			flags->zero = 0;
			(*parse)++;
		}
		if ((width = ft_atoi(*parse)))
			flags->width = width;
		while (ft_isdigit(**parse))
			(*parse)++;
	}
	if (**parse == '.')
	{
		(*parse)++;
		flags->precision = ft_atoi(*parse);
		while (ft_isdigit(**parse))
			(*parse)++;
	}
	flags->specifier = **parse;	//This step will always be last
	if (flags->width < flags->precision)
		flags->width = 0;
	(*parse)++;
}

char		*ft_field(t_flags *flags)
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

char		*ft_data(va_list ap, t_flags *flags)
{
	char	*data;

	data = NULL;
	if (flags->specifier == 's')
		data = ft_save_str(ap, flags);				// Rewrite this function 
	else if (flags->specifier == 'd' || flags->specifier == 'i')
		data = ft_save_int(ap, flags);
	else if (flags->specifier == 'c' || flags->specifier == '%')				// Rewrite this function 
		data = ft_save_char(ap, flags);
	else if (flags->specifier == 'p')				// Rewrite this function 
		data = ft_save_ptr(ap, flags);
	else if (flags->specifier == 'u')				// Rewrite this function 
		data = ft_save_uint(ap, flags);
	else if (flags->specifier == 'x' || flags->specifier == 'X')				// Rewrite this function 
		data = ft_save_hex(ap, flags);
	return (data);
}

void		ft_specifier(va_list ap, t_flags *flags, size_t *char_count)
{
	/* All of these functions' declarations have to be fixed to not include parse */
	char	*field;
	char	*data;
	int		field_len;
	int		data_len;
	int		offset;

	field = ft_field(flags);		// Corner case where you get spaces before AND after specifier?? Ie "%-5.4d", 123. Output will be "0123 ""
	field_len = ft_strlen(field);
	data = ft_data(ap, flags);			// SEGFAULT
	data_len = ft_strlen(data);
	offset = field_len - data_len;
	if (offset < 0)
		ft_putstr_fd(data, 0);
	else
	{
		if (!flags->dash)
			ft_memcpy(field + offset, data, data_len);
		else
			ft_memcpy(field, data, data_len);
	}
	char_count += ft_strlen(field);
	ft_putstr_fd(field, 0);
	free(field);
	free(data);
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
	while (*parse)
	{
		ft_walk(&parse, &char_count);
		if (*parse != '%')
			break;
		ft_parse_flags(&parse, &flags);
		ft_specifier(ap, &flags, &char_count);
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
