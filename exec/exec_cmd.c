#include "../minishell.h"

int	has_build_in(char **cmd)
{
	if (!ft_strncmp(cmd[0], "echo", 4) && ft_strlen(cmd[0]) == 4)
		return (1);
	else if (!ft_strncmp(cmd[0], "cd", 2) && ft_strlen(cmd[0]) == 2)
		return (1);
	else if (!ft_strncmp(cmd[0], "pwd", 3) && ft_strlen(cmd[0]) == 3)
		return (1);
	else if (!ft_strncmp(cmd[0], "export", 6) && ft_strlen(cmd[0]) == 6)
		return (1);
	else if (!ft_strncmp(cmd[0], "unset", 5) && ft_strlen(cmd[0]) == 5)
		return (1);
	else if (!ft_strncmp(cmd[0], "env", 3) && ft_strlen(cmd[0]) == 3)
		return (1);
	else if (!ft_strncmp(cmd[0], "exit", 4) && ft_strlen(cmd[0]) == 4)
		return (1);
	return (0);
}

void	exec_cmd(t_shell *shell, t_unit *unit)
{
	char	**argv;
	char	**envp;

	dollar(unit, shell);
	envp = create_env_mass(shell->env);
	argv = create_argv(unit);
	if (has_build_in(argv))
		shell->ret = built_in_cmd(argv, shell->env);
	else
		shell->ret = exec_execve(shell, argv, envp);
	shell->last_ret = shell->ret;
	if (g_sig.ch_flagint || g_sig.ch_flagquit)
	{
		shell->ret = g_sig.exit;
		shell->last_ret = g_sig.exit;
	}
	init_sig();
	ft_free(argv);
	ft_free(envp);
	shell->recurs_exit = 1;
}
