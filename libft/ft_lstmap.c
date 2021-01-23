/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsimelio <jsimelio@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 18:29:14 by jsimelio      #+#    #+#                 */
/*   Updated: 2020/11/22 19:44:31 by jsimelio      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_item;
	t_list	*start;

	if (!lst)
		return (NULL);
	start = NULL;
	while (lst)
	{
		new_item = ft_lstnew((*f)(lst->content));
		if (!new_item)
		{
			while (start)
			{
				new_item = start->next;
				(*del)(start->content);
				free(start);
				start = new_item;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&start, new_item);
		lst = lst->next;
	}
	return (start);
}
