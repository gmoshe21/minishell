#include "../minishell.h"
#include "../libft/libft.h"

void make_str(t_mini *mini, int i)
{
	char *str;
	int j;

	j = 0;
	i = 0;
	mini->line = ft_strtrim(mini->line, " ");
	while (ft_isascii(mini->line[i]) && *mini->line != '\0'&& mini->line[i] != ' ')
	{
		if (mini->line[i] == '\'')
		{
			i++;
			while (mini->line[i] != '\'' && mini->line[i] != '\0')
				i++;
		}
		if (mini->line[i] == '\"')
		{
			i++;
			while (mini->line[i] != '\"' && mini->line[i] != '\0')
				i++;
		}
		if (mini->line[i] == '\0')
			break;
		i++;
	}
	if (i > 0)
	{
		ft_lstadd_back(&mini->l_ptr, ft_lstnew(ft_substr(mini->line, j, i - j)));
		str = mini->line;
		mini->line = ft_substr(mini->line, i, ft_strlen(mini->line) - i);
		if (mini->line != NULL)
			free(str);
	}
	if (mini->line[0] != '\0')
		make_str(mini,i);
}

void line_work(t_mini *mini)
{
	int i;
	char *str;
	char *ptr;

	i = 0;
	while (mini->line[i])
	{
		mini->line = ft_strtrim(mini->line, " ");
		while (ft_isascii(mini->line[i]) && *mini->line != '\0' && mini->line[i] != ' ')
			i++;
		if (i > 0)
		{
			ptr = ft_calloc(i + 1, 1);
			ft_strlcpy(ptr, mini->line, i + 1);
			mini->lst = ft_lstnew(ptr);
			mini->l_ptr = mini->lst;
			mini->line = ft_substr(mini->line, i, ft_strlen(mini->line) + 1);
			make_str(mini, i);
		}
		// free(str);
		return ;
	}
}