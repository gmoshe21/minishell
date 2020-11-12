#include "../minishell.h"

void	lets_free(t_mini *mini)
{
	while(mini->d_lst)
	{
		free(mini->d_lst->content);
		mini->d_lst = mini->d_lst->next;
	}
	free(mini->def);
	// if (mini->command)
	// 	free(mini->command);
}

int main(int argc,char **argv, char **envp)
{
	t_mini mini;
	int i = 0;
	mini.fd = 0;
	mini.lst = NULL;
	int x;

	x = 0;
	mini.flag_pipe = 0;
	while(envp[x])
		x++;
	mini.env = ft_calloc(x + 1, sizeof(char**));
	x = 0;
	while (envp[x])
	{
		mini.env[x] = ft_strdup(envp[x]);
		x++;
	}
	i = 0;
	mini.lst = NULL;
	mini.exp = NULL;
	write(1, "msh >> \n", 7);
	while (get_next_line(mini.fd, &mini.line))
	{
		mini.def = (t_defhf *)malloc(sizeof(t_defhf));
		mini.def->head = mini.def->tail = NULL;
		mini.def->size = 0; 
		check_export_end_environment_variable(&mini);
		line_work(&mini);
		check_for_command(&mini);
		what_a_command(&mini);
		write(1, "msh >> \n", 7);
		lets_free(&mini);
	}
	return (0);
}