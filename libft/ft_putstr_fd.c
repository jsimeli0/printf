/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 16:10:22 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/25 16:17:01 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd, int len)
{
	if (!s)
		return ;
	while (len)
	{
		ft_putchar_fd(*s, fd);
		s++;
		len--;
	}
}
