#include "ft_string.h"

size_t	ft_strclen(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str && *str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}
