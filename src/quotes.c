#include "../minishell.h"

char *slash(t_mini *mini, char *str, int i)
{
	int j;
	char *new_str;
	char *zam;
	int quo;

	quo = 0;
	zam = ft_calloc(2, sizeof(char));
	j = i;
	new_str = ft_substr(str, 0, i);
	while (str[i] != '\0')
	{
		if (str[i] != '\\')
		{
			*zam = str[i];
			new_str = ft_strjoin(new_str, zam);
		}
		if (str[i] == '\\' && str[i + 1] == '\\')
		{
			*zam = str[i];
			new_str = ft_strjoin(new_str, zam);
		}
		i++;
	}
	// if (quo % 2 != 0)
	// {
	// 	write(1, "STOP IT\n", 8);
	// 	exit(0);
	// }
	str = ft_strdup(new_str);
	return (str);
}

char *double_quotes(t_mini *mini, char *str, int i)
{
	int j;
	char *new_str;
	char *zam;
	int quo;

	quo = 0;
	zam = ft_calloc(2, sizeof(char));
	j = i;
	new_str = ft_substr(str, 0, i);
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && (str[i + 1] == '\\' || str[i + 1] == '\"' || str[i + 1] == '$'))
		{
				i++;
				if (str[i] == '\"')
				{
					*zam = str[i];
					new_str = ft_strjoin(new_str, zam);
					i++;
				}
		}
		if (str[i] != '\"')
		{
			if (str[i] == '\\' && (str[i + 1] == '\\' || str[i + 1] == '\"' || str[i + 1] == '$'))
				i++;
			*zam = str[i];
			new_str = ft_strjoin(new_str, zam);
		}
		if (str[i] == '\"')
			quo++;
		i++;
	}
	if (quo % 2 != 0)
	{
		write(1, "STOP IT\n", 8);
		exit(0);
	}
	str = ft_strdup(new_str);
	return (str);
}

char *one_quotes(t_mini *mini, char *str, int i)
{
	int j;
	char *new_str;
	char *zam;
	int quo;

	quo = 0;
	mini->quo_ch = 0;
	zam = ft_calloc(2, sizeof(char));
	j = i;
	new_str = ft_substr(str, 0, i);
	while (str[i] != '\0')
	{
		if (str[i] != '\'')
		{
			*zam = str[i];
			new_str = ft_strjoin(new_str, zam);
		}
		if (str[i] == '\'')
			quo++;
		i++;
	}
	if (quo % 2 != 0)
	{
		write(1, "STOP IT\n", 8);
		exit(0);
	}
	str = ft_strdup(new_str);
	return (str);
}

void quotes(t_mini *mini)
{
	t_list *new_lst;
	char *str;
	int i;

	new_lst = mini->l_ptr;
	i = 0;
	while (new_lst)
	{
		str = ft_strdup(new_lst->content);
		while (str[i] != '\"' && str[i] != '\'' && str[i] != '\0' && str[i] != '\\')
			i++;
		if (str[i] == '\'')
			new_lst->content =	one_quotes(mini, str, i);
		if (str[i] == '\"')
			new_lst->content =	double_quotes(mini, str, i);
		if (str[i] == '\\')
			new_lst->content =	slash(mini, str, i);
		new_lst = new_lst->next;
		i = 0;
	}
}