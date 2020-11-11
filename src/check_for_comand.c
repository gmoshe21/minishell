#include "../minishell.h"

char **search_for_path(t_mini *mini)
{
	char **double_ptr;
	char *ptr;
	int i;
	
	i = 0;
	double_ptr = mini->env;
	while (double_ptr++)
	{
		ptr = *double_ptr;
		if (ft_strncmp(ptr, "PATH", 4) == 0)
		{
			ptr = ft_strdup(ptr);
			while (ptr[i] != '/')
				i++;
			ptr = ft_substr(ptr, i, ft_strlen(ptr) - i);
			double_ptr = ft_split(ptr, ':');
			return (double_ptr);
		}
	}
	return (NULL);
}

char	*search_for_dir(t_mini *mini, char **argv)
{
	DIR *ptr;
	struct dirent *entry;
	char *ret_str;
	char **str = search_for_path(mini);
	int i = 0;
	while ((ptr = opendir(str[i])))
	{
		ptr = opendir(str[i]);
		while ((entry = readdir(ptr)) != NULL)
		{
			if (ft_strncmp(argv[0], entry->d_name, ft_strlen(entry->d_name)) == 0)
			{
				str[i] = ft_strjoin(str[i], "/");
				ret_str = ft_strjoin(str[i], argv[0]);
				return (ret_str);
			}
		}
		i++;
	}
	return ("ptr");
}

void	do_exec(t_mini *mini)
{
	pid_t pid;
	char **argv;
	int x;
	x = 0;

	argv = ft_calloc(ft_lstsize(mini->l_ptr) + 1, sizeof(char**));
	while (mini->l_ptr != NULL)
	{
		argv[x] = ft_strdup(mini->l_ptr->content);
		ft_lstdelone(mini->l_ptr, free);
		mini->l_ptr = mini->l_ptr->next;
		x++;
	}
	char *file = search_for_dir(mini, argv);
	pid = fork();
	if (pid == 0)
	{
		execve(file, argv, mini->env);
	}
	waitpid(pid, NULL, WUNTRACED);
}

void check_for_comand(t_mini *mini)
{
	int i = 0;
	quotes(mini);
	if (ft_strncmp(mini->l_ptr->content, "echo", 5) == 0)
		do_echo(mini);
	else if (mini->l_ptr == NULL)
		return ;
	else if (ft_strncmp(mini->l_ptr->content, "cd", 3) == 0)
		do_cd(mini);
	else if (ft_strncmp(mini->l_ptr->content, "pwd", 4) == 0)
		do_pwd(mini);
	else if (ft_strncmp(mini->l_ptr->content, "export", 7) == 0)
	{

	}
	else if (ft_strncmp(mini->l_ptr->content, "unset", 6) == 0)
	{

	}
	else if (ft_strncmp(mini->l_ptr->content, "env", 4) == 0)
	{

	}
	else if (ft_strncmp(mini->l_ptr->content, "exit", 5) == 0)
		exit (0);
	else
		do_exec(mini);

}