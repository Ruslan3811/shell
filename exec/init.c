#include "../minishell.h"

void	init_ch(t_child *ch)
{
	ch->pid = -1;
	ch->ret = 0;
	ch->status = 0;
}

void	init_pr(t_shell *shell)
{
	shell->exit = 0;
	shell->in = dup(0);
	shell->out = dup(1);
	shell->ret = 0;
	shell->last_ret = 0;
	shell->main_proc = 1;
	init_ch(&shell->ch);
	init_termcap(&shell->tmp);
	init_fd(shell);
	init_sig();
}

void	init_std(t_shell *shell)
{
	dup2(shell->in, 0);
	dup2(shell->out, 1);
}

void	init_fd(t_shell *shell)
{
	shell->pipeout = -1;
	shell->pipein = -1;
	shell->fdin = -1;
	shell->fdout = -1;
}
