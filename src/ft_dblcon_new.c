/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblcon_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 20:40:10 by amarcele          #+#    #+#             */
/*   Updated: 2020/11/04 17:54:21 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dblcon	*ft_dblcon_new(void *content, t_defhf *def)
{
	t_dblcon	*new;

	new = (t_dblcon *)malloc(sizeof(t_dblcon));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	if (def->head == NULL)
		def->head = new;
	if (def->tail == NULL)
		def->tail = new;
	return (new);
}
