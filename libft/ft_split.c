/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 09:36:06 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/11/22 21:23:01 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	words_found(const char *str, char c)
{
	unsigned int		words;
	char				previous;

	words = 0;
	previous = c;
	while (*str)
	{
		if (*str != c && previous == c)
			words++;
		previous = *str;
		str++;
	}
	return (words);
}

static unsigned int	word_length(const char *str, char c)
{
	unsigned int		len;

	if (*str == 0)
		return (0);
	len = 0;
	while (*str != c && *str)
	{
		len++;
		str++;
	}
	return (len);
}

static void			free_strings(char **arr, unsigned int words)
{
	while (words > 0)
	{
		free(arr[words - 1]);
		words--;
	}
}

static int			assign_strings(char const *s, char c, unsigned int words,
					char **arr)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (*s && i < words)
	{
		if (*s == c)
			s++;
		else
		{
			len = word_length(s, c);
			arr[i] = ft_calloc(1, sizeof(char) * (len + 1));
			if (!arr[i])
			{
				free_strings(arr, i + 1);
				free(arr);
				return (1);
			}
			ft_memcpy(arr[i], s, len);
			i++;
			s += len;
		}
	}
	return (0);
}

char				**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	words;
	int				check;

	if (!s)
		return (NULL);
	words = words_found(s, c);
	arr = malloc(sizeof(char*) * (words + 1));
	if (!arr)
		return (NULL);
	arr[words] = 0;
	check = assign_strings(s, c, words, arr);
	if (check == 1)
		return (NULL);
	return (arr);
}
