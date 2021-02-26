/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_absolute.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 16:25:36 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/15 13:36:39 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_absolute(long long int n)
{
	if (n < 0)
		n = -n;
	return (n);
}
