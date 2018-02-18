#include "lem_in.h"

size_t ft_strclen(const char *str, int c)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str++ == c)
			i++;
	}
	return (i);
}
