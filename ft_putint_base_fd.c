/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putint_base_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 16:32:36 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/07 19:10:58 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		main(void)
{
	int		hex = 16546;
	char	*base = "0123456789abcdef";
	ft_putint_base_fd(hex, base, 1);
	return (0);
}

void	ft_putint_base_fd(int nbr, char *base, int fd)
{
	int baselen;

	baselen = ft_strlen(base);
	printf("%d\n");
	if (nbr > baselen)
	{
		ft_putint_base_fd((nbr / baselen), base, fd);
		ft_putchar_fd((nbr % baselen) + '0', fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}
