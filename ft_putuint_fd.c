/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putuint_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 18:32:41 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/12/07 18:46:37 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_putuint_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putuint_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
