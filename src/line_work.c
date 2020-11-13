#include "../minishell.h"
#include "../libft/libft.h"

// void make_str(t_mini *mini, int i)
// {
// 	char *str;
// 	int j;

// 	j = 0;
// 	i = 0;
// 	mini->line = ft_strtrim(mini->line, " ");
// 	while (ft_isascii(mini->line[i]) && *mini->line != '\0'&& mini->line[i] != ' ')
// 	{
// 		if (mini->line[i] == '\'')
// 		{
// 			i++;
// 			while (mini->line[i] != '\'' && mini->line[i] != '\0')
// 				i++;
// 		}
// 		if (mini->line[i] == '\"')
// 		{
// 			i++;
// 			while (mini->line[i] != '\"' && mini->line[i] != '\0')
// 				i++;
// 		}
// 		if (mini->line[i] == '\0')
// 			break;
// 		i++;
// 	}
// 	if (i > 0)
// 	{
// 		ft_lstadd_back(&mini->l_ptr, ft_lstnew(ft_substr(mini->line, j, i - j)));
// 		str = mini->line;
// 		mini->line = ft_substr(mini->line, i, ft_strlen(mini->line) - i);
// 		if (mini->line != NULL)
// 			free(str);
// 	}
// 	if (mini->line[0] != '\0')
// 		make_str(mini,i);
// }

// void line_work(t_mini *mini)
// {
// 	int i;
// 	char *str;
// 	char *ptr;

// 	i = 0;
// 	while (mini->line[i])
// 	{
// 		mini->line = ft_strtrim(mini->line, " ");
// 		while (ft_isascii(mini->line[i]) && *mini->line != '\0' && mini->line[i] != ' ')
// 			i++;
// 		if (i > 0)
// 		{
// 			ptr = ft_calloc(i + 1, 1);
// 			ft_strlcpy(ptr, mini->line, i + 1);
// 			mini->lst = ft_lstnew(ptr);
// 			mini->l_ptr = mini->lst;
// 			mini->line = ft_substr(mini->line, i, ft_strlen(mini->line) + 1);
// 			make_str(mini, i);
// 		}
// 		// free(str);
// 		return ;
// 	}
// }

void make_touch(t_mini *mini)
{
	int fd;

	fd = 0;
	while (mini->d_lst)
	{
		if (ft_strncmp(mini->d_lst->content, ">", 2) == 0)
		{
			mini->d_lst = mini->d_lst->next;
			fd = open(mini->d_lst->content, O_CREAT | O_RDWR | O_APPEND | O_TRUNC, 0666);
			close (fd);
		}
		mini->d_lst = mini->d_lst->next;
	}
}

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
		// ft_lstadd_back(&mini->l_ptr, ft_lstnew(ft_substr(mini->line, j, i - j)));
		push_back(mini->def, ft_dblcon_new(ft_substr(mini->line, j, i - j), mini->def));
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
			// mini->lst = ft_lstnew(ptr);
			mini->d_lst = ft_dblcon_new(ptr, mini->def);
			// mini->l_ptr = mini->lst;
			mini->line = ft_substr(mini->line, i, ft_strlen(mini->line) + 1);
			make_str(mini, i);
		}
		// printf("%i\n", mini->def->size);
		// while (mini->d_lst)
		// {
		// 	// printf("%s\n", mini->d_lst->content);
		// 	mini->d_lst = mini->d_lst->next;
		// }
		// free(str);
		make_touch(mini);
		mini->d_lst = mini->def->head;
		return ;
	}
}