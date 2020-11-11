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

void	do_cd(t_mini *mini)
{
	t_list *l_dir;
	l_dir = mini->lst->next;
	char *str;

	if (l_dir)
		chdir(l_dir->content);
	else
	{
		str = get_pwd(mini->env);
		chdir(str);
	}
}