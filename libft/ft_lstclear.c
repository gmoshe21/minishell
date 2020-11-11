/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:15:36 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/22 15:29:51 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *elm;
	t_list *delm;

	elm = *lst;
	while (elm)
	{
		delm = elm;
		elm = elm->next;
		ft_lstdelone(delm, del);
	}
	*lst = NULL;
}
