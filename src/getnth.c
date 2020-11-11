#include "../minishell.h"

t_dblcon *getnth(t_defhf *def, int index)
{
	t_dblcon *lst;
	int i;

	lst = def->head;
	i = 0;
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}