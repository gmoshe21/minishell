/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:41:10 by gmoshe            #+#    #+#             */
/*   Updated: 2020/11/11 13:30:48 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	freeing(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		free(str[i++]);
	free(str);
}

int		check_existence_of_a_variable(char **exp, char *str)
{
	int	i;

	i = 0;
	if (!exp)
		return (0);
	while (exp[i])
	{//printf("<%s>\n", exp[i]);
		if (!(ft_memcmp(str, exp[i++], ft_strlen(str))))
		{
			//printf("|%s|\n", exp[i - 1]);
			return (i);
		}
	}
	return (0);
}

int		init_environment(t_mini *shell, char *str)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		if(!(ft_memcmp(str, shell->env[i], ft_strper(str, '='))))
			{
				free(shell->env[i]);
				shell->env[i] = ft_strdup(str);
				return (1);
			}
		i++;
	}
	return (0);
}

void	check_environment(t_mini *shell, char *str)
{
	int	i=0;
	
	if(ft_strchr(str, '='))
	{
		init(shell, str);
		if (!(init_environment(shell, str)))
			shell->env = check_exp(shell->env, str);
	}
	else
	{
		if ((i = check_existence_of_a_variable(shell->exp, str)) && !(check_existence_of_a_variable(shell->env, str)))
		{
			if (!(ft_strchr(shell->exp[i - 1], '=')))
				shell->exp[i - 1] = ft_strjoin(shell->exp[i - 1], "=");
			shell->env = check_exp(shell->env, shell->exp[i - 1]);
		}
		else if (!(check_existence_of_a_variable(shell->env, str)))
			{
				str = ft_strjoin(str, "=");
				shell->env = check_exp(shell->env, str);
			}
	}
}