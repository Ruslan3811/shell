#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!dst || !src)
		return (0);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (len)
	{
		len--;
		while (*ptr_src && len--)
			*ptr_dst++ = *ptr_src++;
		*ptr_dst = '\0';
	}
	return (ft_strlen(src));
}
