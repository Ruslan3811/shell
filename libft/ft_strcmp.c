#include "libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!str1 || !str2)
		return (1);
	while (str1[i] && str2[i])
	{
		cnt = str1[i] - str2[i];
		if (cnt != 0)
			return (cnt);
		i++;
	}
	return (str1[i] - str2[i]);
}
