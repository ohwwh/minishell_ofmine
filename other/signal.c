#include "minishell.h"

extern t_global_set	g_set;

void	sig_print(int signum)
{
	if (signum == SIGINT)
		write(0, "^C\n", 3);
	else if (signum == SIGQUIT)
		write(0, "^\\Quit: 3\n", 10);
}

void	sig_handler(int signum)
{
	const int	pid = waitpid(-1, 0, 0);

	if (pid != -1 && g_set.flag != 2) //자식 프로세스인 경우
	{
		sig_print(signum);
		return ;
	}
	if (signum == SIGINT && g_set.flag == 2)
	{
		close(STDIN_FILENO);
		printf(">\n");
		g_set.flag = 3;
		return ;
	}
	if (signum == SIGINT && g_set.flag != 2)
	{
		printf("\n");
		rl_replace_line("", 1);
	}
	if (signum == SIGINT || signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}
