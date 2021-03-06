#include "../minishell.h"

int	in_quote(char *str, int	pos)
{
	int	i;
	int	type;

	type = 0;
	i = -1;
	while (++i < pos && str[i])
	{
		if (i > 0 && str[i - 1] == '\\' && type != 1)
			;
		else if (!type && str[i] == '\'')
			type = 1;
		else if (!type && str[i] == '\"')
			type = 2;
		else if (type == 1 && str[i] == '\'')
			type = 0;
		else if (type == 2 && str[i] == '\"')
			type = 0;
	}
	return (type);
}

int	quote_err(char *line)
{
	if (in_quote(line, ft_strlen(line)))
	{
		ft_putstr_fd("minishell: Error: quote\n", 1);
		free(line);
		return (1);
	}
	return (0);
}

void	print_minishell(void)
{
	char	*path;

	path = changing_tilda();
	ft_putstr_fd(path, 2);
	ft_putstr_fd(" minishell > ", 2);
	free(path);
}

char	*fd_or_std(t_shell *shell)
{
	char	*line;

	line = NULL;
	if (set_flag(&shell->tmp, &shell->term))
	{
		if (!get_next_line(0, &line))
		{
			shell->exit = 1;
			close(0);
		}
	}
	else
	{
		print_minishell();
		line = ft_strdup(termcap(&shell->tmp));
		reset_flag(&shell->term);
	}
	return (line);
}

t_unit	*parse(t_shell *shell)
{
	char	*line;

	line = fd_or_std(shell);
	if (g_sig.flagint)
		shell->last_ret = g_sig.exit;
	if (quote_err(line) || !line)
		return (NULL);
	line = space_line(line);
	shell->first = set_units(line);
	set_unit_type(shell->first);
	free(line);
	if (!check_valid(shell->first))
		shell->first = free_units(shell->first);
	return (shell->first);
}
