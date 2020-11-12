#include "../minishell.h"

void what_a_command(t_mini *mini)
{
	// if (mini->token == TO_ECHO)
	// 	do_echo(mini->args);
	if (mini->token == TO_EXEC)
		do_exec(mini->args, mini->env, mini->command, mini->flag_pipe);
	if (mini->token == TO_CD)
		do_cd(mini->args, mini->env);
}