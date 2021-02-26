/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 17:00:11 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/10 14:51:39 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
/* Delete these includes before submitting */
// # include <unistd.h>
// # include <stdio.h>

typedef struct	s_flags
{
	char		specifier;		// Change for specifier
	int			width;			// Min field width
	int			dash;			// Left-justifies the result, pads on the right with blanks. If not given, it right-justifies the result, pads on the left with zeros or blanks
	int			precision;			//  Maximum number of characters to print; for integers, minimum number of digits to print
	int			zero;			// Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
	int			star;			// The argument list supplies the width specifier, which must precede the actual argument being formatted
	int			sign;
	int			character;
}				t_flags;

char			*ft_precision(char *data, t_flags *flags);
char			*ft_save_int(va_list ap, t_flags *flags);
char			*ft_save_uint(va_list ap, t_flags *flags);
char			*ft_save_ptr(va_list ap, t_flags *flags);
char			*ft_save_hex(va_list ap, t_flags *flags);
char			*ft_save_str(va_list ap, t_flags *flags);
char			*ft_save_char(va_list ap, t_flags *flags);
void			ft_walk(char **parse, size_t *char_count);
void			ft_init_flags(t_flags *flags);
void			ft_parse_flags(va_list ap, char **parse, t_flags *flags);
char			*ft_field(t_flags *flags);
char			*ft_data(va_list ap, t_flags *flags);
void			ft_specifier(va_list ap, t_flags *flags, size_t *char_count);
int				ft_printf(const char *str, ...);
#endif
