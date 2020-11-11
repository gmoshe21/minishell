#include "../minishell.h"

int main(int argc,char **argv, char **envp)
{
	t_mini mini;
	int i = 0;
	mini.fd = 0;
	mini.lst = NULL;
	int x;

	x = 0;
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
		check_export_end_environment_variable(&mini);
		line_work(&mini);
		check_for_comand(&mini);
		write(1, "msh >> \n", 7);
		// free(mini.env);
	}
	return (0);
}