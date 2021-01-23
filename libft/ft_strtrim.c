/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 14:24:41 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/11/22 17:39:54 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			length;
	int			end;
	const char	*s1copy;

	start = 0;
	end = 0;
	s1copy = s1;
	if (!set || !s1)
		return ((char *)s1);
	while (*s1copy && ft_strchr(set, *s1copy))
	{
		start++;
		s1copy++;
	}
	length = ft_strlen(s1copy);
	while (*s1copy)
	{
		if (!ft_strchr(set, *s1copy))
			end = 0;
		else
			end++;
		s1copy++;
	}
	return ((char *)ft_substr(s1, start, length - end));
}
