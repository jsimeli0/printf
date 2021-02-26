/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_main.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 10:04:17 by jsimelio      #+#    #+#                 */
/*   Updated: 2021/02/02 16:27:15 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char	*str;
	long long		n;

	n = 4550373275;
	str = ft_itoa_base(n, 16);
	printf("%s\n", str);
	free(str);
	return (0);
}
