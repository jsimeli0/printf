/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:24:31 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/11/22 18:37:29 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_element;

	list_element = malloc(sizeof(t_list));
	if (!list_element)
		return (NULL);
	list_element->content = content;
	list_element->next = NULL;
	return (list_element);
}
