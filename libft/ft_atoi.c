#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	num;
	int				sign;

	sign = 1;
	num = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str++ - '0';
		if (num > 4096)
			return (num);
	}
	if (num < 0 && sign < 0)
		return (0);
	num = sign * num;
	return ((int)num);
}
