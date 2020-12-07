/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/25 16:32:36 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/08/25 20:48:02 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int baselen;

	baselen = ft_strlen(base);
	if (nbr > baselen)
	{
		ft_putnbr_base((nbr / baselen), base);
		ft_putchar((nbr % baselen) + '0');
	}
	else
		ft_putchar(base[nbr]);
}
