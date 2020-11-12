#ifndef MINISHELL
# define MINISHELL

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include <dirent.h>
# include <stdio.h>

# define ECHO = "echo"
# define CD = "cd"
# define PWD = "pwd"
# define EXPORT = "export"
# define UNSET = "unset"
# define ENV = "env"
# define EXIT = "exit"

typedef enum Token
{
	TO_ECHO,
	TO_GREAT,
	TO_GRGR,
	TO_LESS,
	TO_EXEC,
	TO_DOTCOMMA,
	TO_PIPE,
	TO_CD,
	TO_PWD,
	TO_EXPORT,
	TO_UNSET,
	TO_ENV,
	TO_EXIT,
}			Token;

typedef struct		s_dblcon
{
	void			*content;
	struct s_dblcon			*next;
	struct s_dblcon			*prev;
}					t_dblcon;

typedef struct	s_defhf
{
	int size;
	struct s_dblcon *tail;
	struct s_dblcon *head;
}				t_defhf;

typedef struct	s_mini
{
	int			fd;
	int			flag_pipe;
	char		*line;
	char		**env;
	char		**exp;
	char		**args;
	int			quo_ch;
	char		*command;
	Token		token;
	t_defhf		*def;
	t_dblcon	*d_lst;
	t_list		*l_ptr;
	t_list		*lst;
}				t_mini;


void	push_front(t_defhf *def, t_dblcon *tmp);
void	do_exec(char **args, char **env, char *command, int flag);
void	push_back(t_defhf *def, t_dblcon *tmp);
void insert(t_defhf *def, int index, t_dblcon *ins);
t_dblcon *getnth(t_defhf *def, int index);
t_dblcon	*ft_dblcon_new(void *content, t_defhf *def);
void 	line_work(t_mini *mini);
void 	check_for_command(t_mini *mini);
void do_echo(char **args);
void 	quotes(t_mini *mini);
void	do_cd(char **args, char **env);
void do_pwd(char **args, char **env);

void	check_export_end_environment_variable(t_mini *mini);
void	delete_variable(t_mini *shell, char *line);
char	*change_line(char *line, int delete, int addition, char *par);
char	**rewriting(char **exp, int delete);
int		ft_strper(char *str, char c);
int		delete(char *str);
void	export(t_mini *shell, char *line);
int		init(t_mini *shell, char *line);
char	**check_exp(char **str, char *line);
void	print(char **str);
void	check_environment(t_mini *shell, char *str);
int		init_environment(t_mini *shell, char *str);
int		check_export(char *line);
void	freeing(char **str);
void	what_a_command(t_mini *mini);

#endif
