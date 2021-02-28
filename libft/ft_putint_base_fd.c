/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putint_base_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 16:32:36 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/28 23:31:29 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_putint_base_fd(int nbr, char *base, int fd)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (nbr >= baselen)
	{
		ft_putint_base_fd((nbr / baselen), base, fd);
		ft_putchar_fd(base[nbr % baselen], fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}
