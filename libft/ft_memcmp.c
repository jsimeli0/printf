/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:50:28 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/11/02 16:47:08 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	int				len;

	s1_copy = (unsigned char*)s1;
	s2_copy = (unsigned char*)s2;
	len = (int)n;
	while (len)
	{
		if (*s1_copy == *s2_copy)
		{
			s1_copy++;
			s2_copy++;
			len--;
		}
		else
			return (*s1_copy - *s2_copy);
	}
	return (0);
}
