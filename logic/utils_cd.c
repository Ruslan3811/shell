#include "../minishell.h"

int	arg_str(char **cmd)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(cmd[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit (255);
}

void	output_mistake_cd(char *str1, char *str2, char *str3)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
}

int	info_mistake(char *cmd)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (0);
}
