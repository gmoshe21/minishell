#include "../minishell.h"

void do_echo(t_mini *mini)
{
	int nflag;
	pid_t pid;
	char **argv;
	int x;
	int i;

	x = 0;
	nflag = 0;
	i = 0;
	argv = ft_calloc(ft_lstsize(mini->l_ptr) + 1, sizeof(char**));
	while (mini->l_ptr != NULL)
	{
		argv[x] = ft_strdup(mini->l_ptr->content);
		ft_lstdelone(mini->l_ptr, free);
		mini->l_ptr = mini->l_ptr->next;
		x++;
	}
	x = 1;
	if (ft_strncmp(argv[x], "-n" , 2) == 0)
	{
		nflag = 1;
		x++;
	}
	while (argv[x])
	{
		i = 0;
		// printf("%s\n", argv[x]);
		while (argv[x][i])
		{
			write(1, &argv[x][i], 1);
			i++;
		}
		x++;
		if (argv[x] != NULL)
			write(1, " ", 1);
	}
	if (nflag == 0)
		write(1, "\n", 1);
}