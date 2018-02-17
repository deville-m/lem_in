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

char		**combi(t_dlist *try, size_t j)
{
	size_t	i;
	char	**matrice;
	t_dlist	*tmp;
	t_dlist	*cmp;

	if (!try)
		return (NULL);
	j = 0;
	matrice = (char **)malloc(sizeof(char *) * (ft_dlstlen(try) + 1));
	tmp = try;
	while (tmp)
	{
		i = 0;
		cmp = try;
		matrice[j] = (char *)malloc(sizeof(char) * (ft_dlstlen(try) + 1));
		while (cmp)
		{
			matrice[j][i++] = (!path_cmp(tmp, cmp)) ? '1' : '0';
			cmp = cmp->next;
		}
		matrice[j++][i] = '\0';
		tmp = tmp->next;
	}
	matrice[j] = NULL;
	return (matrice);
}

size_t	compatible(char **matrice)
{
	size_t	i;

	i = 0;
	if (!matrice)
		return (0);
	while (matrice && matrice[i])
	{
		if (ft_strclen(matrice[i], '0') > 1)
			return (0);
		i++;
	}
	return (1);
}

t_dlist	*ft_dlstdup(t_dlist *src)
{
	t_dlist	*res;
	t_dlist	*tmp;
	t_dlist	*dup;

	dup = NULL;
	while (src)
	{
		res = NULL;
		tmp = LIST(src);
		while (tmp)
		{
			ft_dlstappend(&res, ft_dlstlink(ROOM(tmp), sizeof(*tmp)));
			tmp = tmp->next;
		}
		ft_dlstprepend(&dup, ft_dlstlink(res, sizeof(t_dlist)));
		src = src->next;
	}
	return (dup);
}

t_dlist	*group_up(t_dlist *try)
{
	t_dlist	*group;
	char	**matrice;

	group = NULL;
	while (try)
	{
		ft_dlstprepend(&group, ft_dlstlink(LIST(try), sizeof(*try)));
		if (!compatible(matrice = combi(group, 0)))
		{
			ft_dlstpop(&group);
			group->prev = NULL;
		}
		ft_tabdel(matrice);
		try = try->next;
	}
	return (group);
}
