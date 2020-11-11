/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:51:24 by amarcele          #+#    #+#             */
/*   Updated: 2020/05/20 16:53:26 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *elm;

	if (*lst)
	{
		elm = *lst;
		while (elm->next)
			elm = elm->next;
		elm->next = new;
	}
	else
		*lst = new;
}
