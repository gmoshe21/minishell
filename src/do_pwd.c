#include "../minishell.h"

static char *get_pwd(char **env)
{
	char *str;

	while (*env++)
	{
		str = ft_strdup(*env);
		if (ft_strncmp(str, "PWD", 3) == 0)
		{
			str = ft_substr(str, 4, ft_strlen(str));
			return (str);
		}
	}
	return (NULL);
}

void do_pwd(char **args, char **env)
{
	// t_list *l_dir;
	// l_dir = mini->lst->next;
	char *str;
	int i;

	i = 0;
	if (args[1] != NULL)
		write(1, "to many arguments\n", 18);
	else
	{
		str = get_pwd(env);
		while (str[i])
			i++;
		str = ft_calloc(1024, sizeof(char));
		getcwd(str,1024);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
}