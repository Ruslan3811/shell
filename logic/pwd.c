#include "../minishell.h"

int	pwd(char **cmd)
{
	char	*buf;
	int		exc_sign;

	exc_sign = 1;
	if (cmd && cmd[1])
		exc_sign = has_exclamation_sign (&cmd[1]);
	buf = getcwd(NULL, 0);
	ft_putstr_fd (buf, 1);
	ft_putstr_fd ("\n", 1);
	if (!exc_sign)
		ft_putstr_fd ("\n", 1);
	free (buf);
	return (0);
}
