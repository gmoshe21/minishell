#include "../minishell.h"

char *get_pwd(char **env)
{
	char *str;

	while (*env++)
	{
		str = ft_strdup(*env);
		if (ft_strncmp(str, "HOME", 4) == 0)
		{
			str = ft_substr(str, 5, ft_strlen(str));
			return (str);
		}
	}
	return (NULL);
}

void	do_cd(char **args, char **env)
{
	// t_list *l_dir;
	// l_dir = mini->lst->next;
	char *str;

	if (args[1])
		chdir(args[1]);
	else
	{
		str = get_pwd(env);
		chdir(str);
	}
}