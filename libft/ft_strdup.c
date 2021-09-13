#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	if (!s1)
		return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
