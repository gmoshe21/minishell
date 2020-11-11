#include "../minishell.h"

void insert(t_defhf *def, int index, t_dblcon *ins)
{
	t_dblcon *elm = NULL;
	// t_dblcon *ins = NULL;
	
	elm = getnth(def, index);
	if (elm == NULL)
		exit (0);
	// ins = (t_dblcon *)malloc(sizeof(t_dblcon));
	// ins->content = content;
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next)
		elm->next->prev = ins;
	elm->next = ins;
	if (!elm->prev)
		def->head = elm;
	if (!elm->prev)
		def->tail = elm;
	def->size++;
}