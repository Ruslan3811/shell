#include "../minishell.h"

void	lstdup(t_env **envi_dup, t_env *envi)
{
	t_env	*lst;

	while (envi)
	{
		lst = ft_lstnew (envi->str);
		ft_lstadd_back (envi_dup, lst);
		envi = envi->next;
	}
}
