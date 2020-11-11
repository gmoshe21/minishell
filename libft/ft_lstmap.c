/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:26:45 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/22 15:24:01 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*dellst;

	newlst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		dellst = ft_lstnew((*f)(lst->content));
		if (!dellst)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, dellst);
		lst = lst->next;
	}
	return (newlst);
}
