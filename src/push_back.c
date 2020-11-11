#include "../minishell.h"

void	push_back(t_defhf *def, t_dblcon *tmp)
{
	tmp->next = NULL;
	tmp->prev = def->tail;
	if (def->tail)
		def->tail->next = tmp;
	def->tail = tmp;
	if (def->head == NULL)
		def->head = tmp;
	def->size++;
}