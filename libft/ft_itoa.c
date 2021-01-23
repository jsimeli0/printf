/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 10:04:17 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/11/26 00:18:45 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copystring(char *tmp, size_t i)
{
	int		j;
	char	*str;

	j = 0;
	str = malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	while (tmp[j])
	{
		str[j] = tmp[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static int	ft_sign(char **tmp, int sign)
{
	if (sign == -1)
	{
		(*tmp)--;
		**tmp = '-';
		return (-1);
	}
	return (0);
}

static void	ft_copytmp(char **tmp, int *n, size_t *i)
{
	while (*n != 0)
	{
		(*tmp)--;
		if (*n > 0)
			**tmp = '0' + *n % 10;
		else
			**tmp = '0' - *n % 10;
		*n /= 10;
		(*i)++;
	}
}

char		*ft_itoa(int n)
{
	char	*tmp;
	char	*tmp2;
	size_t	i;
	int		sign;

	i = 1;
	sign = 0;
	tmp = ft_calloc(1, sizeof(char) * (INT_MAX_32BIT + 2));
	if (tmp == NULL)
		return (NULL);
	tmp2 = tmp + INT_MAX_32BIT + 1;
	if (n < 0)
		sign = -1;
	if (n == 0)
	{
		tmp2 = "0";
		i++;
	}
	else
		ft_copytmp(&tmp2, &n, &i);
	if (ft_sign(&tmp2, sign) == -1)
		i++;
	tmp2 = ft_copystring(tmp2, i);
	free(tmp);
	return (tmp2);
}
