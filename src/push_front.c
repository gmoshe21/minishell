#include "../minishell.h"

void	push_front(t_defhf *def, t_dblcon *tmp)
{

	// tmp->content = content;
	tmp->next = def->head;
	tmp->prev = NULL;
	if (def->head)
		def->head->prev = tmp;
	if (def->tail == NULL)
		def->tail = tmp;
	def->head = tmp;
	def->size++;
}