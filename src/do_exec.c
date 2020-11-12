#include "../minishell.h"

char **search_for_path(char **env)
{
	char **double_ptr;
	char *ptr;
	int i;
	
	i = 0;
	double_ptr = env;
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

char	*search_for_dir(char **env, char **argv, char *command)
{
	DIR *ptr;

	struct dirent *entry;
	char *ret_str;
	char **str = search_for_path(env);
	int i = 0;
	while ((ptr = opendir(str[i])))
	{
		ptr = opendir(str[i]);
		while ((entry = readdir(ptr)) != NULL)
		{
			if (ft_strncmp(command, entry->d_name, ft_strlen(entry->d_name)) == 0)
			{
				str[i] = ft_strjoin(str[i], "/");
				ret_str = ft_strjoin(str[i], command);
				return (ret_str);
			}
		}
		i++;
	}
	return ("ptr");
}

void	do_exec(char **args, char **env, char *command, int flag)
{
	pid_t pid;
	char **argv;
	int x;
	x = 0;

	// argv = ft_calloc(ft_lstsize(mini->l_ptr) + 1, sizeof(char**));
	// while (mini->l_ptr != NULL)
	// {
	// 	argv[x] = ft_strdup(mini->l_ptr->content);
	// 	ft_lstdelone(mini->l_ptr, free);
	// 	mini->l_ptr = mini->l_ptr->next;
	// 	x++;
	// }
	char *file = search_for_dir(env, args, command);
	if (flag == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(file, args, env);
		}
		waitpid(pid, NULL, WUNTRACED);
	}
	else
	{
		execve(file, args, env);
		waitpid(pid, NULL, WUNTRACED);
	}
}
