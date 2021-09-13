#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size_s1;
	size_t	size_s2;

	if (!s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	ptr = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, size_s1 + 1);
	ft_strlcpy(ptr + size_s1, s2, size_s2 + 1);
	return (ptr);
}
