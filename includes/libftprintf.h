/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 17:00:11 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/28 23:13:20 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	char		specifier;
	int			width;
	int			dash;
	int			precision;
	int			zero;
	int			star;
	int			sign;
	int			character;
}				t_flags;

typedef struct s_specifier
{
	char		*field;
	char		*data;
	int			field_len;
	int			data_len;
	int			offset;
}				t_specifier;

char			*ft_data(va_list ap, t_flags *flags);
char			*ft_field(t_flags *flags);
void			ft_init_flags(t_flags *flags);
void			ft_parse_flags(va_list ap, char **parse, t_flags *flags);
char			*ft_precision(char *data, t_flags *flags);
int				ft_printf(const char *str, ...);
void			ft_putsign(char *field);
char			*ft_save_char(va_list ap, t_flags *flags);
char			*ft_save_hex(va_list ap, t_flags *flags);
char			*ft_save_int(va_list ap, t_flags *flags);
char			*ft_save_ptr(va_list ap, t_flags *flags);
char			*ft_save_str(va_list ap, t_flags *flags);
char			*ft_save_uint(va_list ap, t_flags *flags);
void			ft_set_width(char **parse, t_flags *flags);
void			ft_specifier(va_list ap, t_flags *flags, size_t *char_count);
void			ft_walk(char **parse, size_t *char_count);
#endif
