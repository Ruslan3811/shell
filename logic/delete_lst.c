#include "../minishell.h"

void	delete_lst(t_env *envi_dup)
{
	t_env	*tmp;

	while (envi_dup)
	{
		tmp = envi_dup;
		envi_dup = envi_dup->next;
		free(tmp->str);
		free(tmp);
	}
}
