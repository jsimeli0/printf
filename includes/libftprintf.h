/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 17:00:11 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/01/26 13:53:50 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
/* Delete these includes before submitting */
# include <unistd.h>
# include <stdio.h>

typedef struct	s_flags
{
	char		specifier;		// Change for specifier
	int			width;			// Min field width
	int			dash;			// Left-justifies the result, pads on the right with blanks. If not given, it right-justifies the result, pads on the left with zeros or blanks
	int			precision;			//  Maximum number of characters to print; for integers, minimum number of digits to print
	int			zero;			// Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
	int			star;			// The argument list supplies the width specifier, which must precede the actual argument being formatted
}				t_flags;


int		ft_printf(const char *str, ...);
#endif
