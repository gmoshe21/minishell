#include "../minishell.h"

void	do_pipe(t_mini *mini)
{
	pid_t pid;
    int mas[2];
    int status;
    int i;
    pipe(mas);
    pid = fork();
	// printf("%s\n", mini->d_lst->content);
	// printf("%s\n", mini->d_lst->prev->content);
    if (pid == 0)
    {
        close(mas[0]);
        dup2(mas[1], 1);
        close(mas[1]);
		mini->flag_pipe = 1;
		what_a_command(mini);
		// search_redir(mini);
		// while (mini->d_lst->prev != NULL && ft_strncmp(mini->d_lst->content, "|", 2) == 0)
		// 	mini->d_lst = mini->d_lst->prev;
		// check_for_comand(mini);
		// exit(0);
		// if(checking_recoded_functions(comand, vars))
		// {
		// 	exit (0);// забирать значение эрно из внутренних функций и передавать сюда
		// }
		// if ((status = execve(path, comand, NULL)) == -1)
		// 	exit(WEXITSTATUS(status));
    }
	else if (pid < 0)
		ft_putendl_fd("error", 2);
	else
    {
        close(mas[1]);
        dup2(mas[0], 0);
        close(mas[0]);
        waitpid(pid, &status, WUNTRACED);
    }
	mini->flag_pipe = 0;
	// printf("%s\n", mini->d_lst->content);
}