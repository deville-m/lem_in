/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/11 18:53:54 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*path_cmp(t_dlist *l1, t_dlist *l2)
{
	t_dlist	*p1;
	t_dlist	*p2;

	if (!l1 || !l2 || !LIST(l1) || !LIST(l2))
		return (NULL);
	p1 = LIST(l1);
	while (p1)
	{
		p2 = LIST(l2);
		while (p2)
		{
			if (p1->content == p2->content)
				return (ROOM(p1));
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (NULL);
}

#include <stdio.h>
#include <limits.h>

char	**ft_tabcpy(char **tab, size_t hauteur)
{
	char	**cpy;
	size_t	j;
	size_t	i;

	j = 0;
	cpy = (char **)malloc(sizeof(char *) * (hauteur + 1));
	while (tab[j])
	{
		i = 0;
		cpy[j] = ft_strdup(tab[j]);
		j++;
	}
	cpy[j] = NULL;
	return (cpy);
}

size_t	ft_tabheight(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

char		**combi(t_dlist *try)
{
	size_t	i;
	size_t	j;
	char	**matrice;
	t_dlist	*tmp;
	t_dlist	*cmp;
	size_t	dlstlen;

	if (!try)
		return(NULL);
	dlstlen = ft_dlstlen(try);
	j = 0;
	matrice = (char **)malloc(sizeof(char *) * (dlstlen + 1));
	tmp = try;
	while (tmp)
	{
		i = 0;
		cmp = try;
		matrice[j] = (char *)malloc(sizeof(char) * (dlstlen + 1));
		while (cmp)
		{
			matrice[j][i++] = (!path_cmp(tmp, cmp)) ? '1' : '0';
			cmp = cmp->next;
		}
		matrice[j++][i] = '\0';
		tmp = tmp->next;
	}
	matrice[j] = NULL;
	j = 0;
	// while (matrice[j])
	// {
	// 	ft_printf("%s\n", matrice[j]);
	// 	j++;
	// }
	return (matrice);
}

t_dlist	*ft_dlstlookfor(t_dlist *list, size_t i)
{
	while (i-- && list)
	{
		list = list->next;
	}
	return (list);
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

int	get_min(t_dlist *try, char **matrice)
{
	int	i;
	int	min;

	if (!matrice || !*matrice)
		return (-1);
	i = 0;
	min = 0;
	while (matrice && matrice[i])
	{
		if (ft_strclen(matrice[min], '0') > ft_strclen(matrice[i], '0'))
				min = i;
		if (ft_strclen(matrice[min], '0') == ft_strclen(matrice[i], '0')
			&& ft_dlstlen(LIST(ft_dlstlookfor(try, min))) > ft_dlstlen(LIST(ft_dlstlookfor(try, i))))
				min = i;
		i++;
	}
	return (min);
}

int	dlstsame(const void *s1, const void *s2)
{
	return ((s1 == s2) ? 0 : 1);
}

t_dlist	*ft_dlstdup(t_dlist *src)
{
	t_dlist	*dup;

	dup = NULL;
	while (src)
	{
		ft_dlstappend(&dup, ft_dlstnew(LIST(src), sizeof(t_dlist)));
		src = src->next;
	}
	return (dup);
}

int	sort_it(t_dlist *l1, t_dlist *l2)
{
	return ((ft_dlstlen(l1) - ft_dlstlen(l2)));
}

t_dlist	*group_up(t_dlist *try)
{
	t_dlist	*group;
	char	**matrice;

	group = NULL;
	while (!group || try)
	{
		ft_dlstprepend(&group, ft_dlstnew(LIST(try), sizeof(*try)));
		if (!compatible(matrice = combi(group)))
			ft_dlstpop(&group);
		try = try->next;
	}
	ft_printf("NEW GRP:\n");
	ft_dlstiter(group, print_path);
	return (group);
}

void	congestion(t_dlist *path)
{
	while (path)
	{
		ROOM(path)->occupied++;
		path = path->next;
	}
}

size_t	cmpsame(t_dlist *try, t_dlist *best)
{
	t_dlist	*tmp1;
	t_dlist	*tmp2;

	while (try && best)
	{
		tmp1 = LIST(try);
		tmp2 = LIST(best);
		while (tmp1 && tmp2
			&& ROOM(tmp1) == ROOM(tmp2))
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		if (tmp1 || tmp2)
			return (0);
		try = try->next;
		best = best->next;
	}
	return (1);
}

size_t	mapcomplete(t_dlist *list, t_room *begin, t_room *goal)
{
	size_t	len;
	size_t	i;
	t_dlist	*tmp;

	tmp = list;
	i = 0;
	len = ft_dlstlen(list);
	while (tmp)
	{
		if (ROOM(tmp)->occupied >= len)
			return (1);
		if (ROOM(tmp) != begin && ROOM(tmp) != goal && ROOM(tmp)->occupied > 1)
			i++;
		tmp = tmp->next;
	}
	ft_printf("MAPCOMPLETE : i = %u | len = %u\n", i, ft_dlstlen(list));
	return ((i >= len - 2) ? 1 : 0);
}

size_t	already(t_dlist *l1, t_dlist *l2)
{
	if (!l1 || !l2)
		return (0);
	while (l1 && l2)
	{
		if (ROOM(l1) != ROOM(l2))
			return (0);
		l1 = l1->next;
		l2 = l2->next;
	}
	return (1);
}

size_t	alreadyfound(t_dlist *list, t_dlist *path)
{
	t_dlist	*l;
	t_dlist *p;

	if (!list)
		return (0);
	while (list)
	{
		p = path;
		l = LIST(list);
		if (already(l, p))
			return (1);
		list = list->next;
	}
	return (0);
}

t_dlist	*get_path(t_dlist *list, t_room *begin, t_room *goal, unsigned nbant)
{
	t_dlist	*path;
	t_dlist	*try;
	t_dlist	*best;
	t_dlist	*group;
	size_t	pick;

	best = NULL;
	try = NULL;
	pick = 0;
	while (!best || (ft_dlstlen(best) < ft_dlstlen(begin->neighbours) + 5 && !mapcomplete(list, begin, goal)))
	{
		// Est-ce tu as trouver un path?
		if ((path = path_finding(list, begin, goal)))
		{
			// Si oui, est-ce que c'est un path qui a deja ete trouver?
			if (!alreadyfound(try, path))
			{
				// Si oui, tu le rajoute a try
				ft_dlstprepend(&try, ft_dlstlink(path, sizeof(*try)));
				pick = 0;
			}
			else
				pick++;
			// J'incremente occupied pour dire qu'un chemin a deja pris ces noeuds
		}
		// Si apres une rotation de tout les neighbours tu ne trouve pas de nouveau path alors tu quitte
		if (pick > ft_dlstlen(begin->neighbours))
			break ;
		// ft_dlstiter(list, print_room);
		ft_printf("path : \n");
		ft_dlstiter(try, print_path);
		// Je regarde si le nouveau group de chemin est meilleur que mon best
		if (score_it((group = group_up(try)), nbant) < score_it(best, nbant))
		{
			ft_dlstdel(&best, NULL);
			best = group;
		}
		else
			ft_dlstdel(&group, NULL);
		ft_printf("best : \n");
		ft_dlstiter(best, print_path);
	}
	ft_dlstdel(&try, NULL);
	return (best);
}

void	prepare(t_dlist *list, t_room *begin, t_room *goal)
{
	t_dlist	*cmp;
	t_dlist *tmp;

	// disconnect(begin);
	// ft_dlstiter(list, print_room);
	tmp = begin->neighbours;
	while (tmp)
	{
		cmp = begin->neighbours;
		while (cmp)
		{
			rm(tmp, ROOM(cmp));
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
	tmp = goal->neighbours;
	while (tmp)
	{
		cmp = goal->neighbours;
		while (cmp)
		{
			rm(tmp, ROOM(cmp));
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
	// disconnect(goal);
	dijkstra(list, begin);
}

void	reverseall(t_dlist *list)
{
	t_dlist	*tmp;

	while (list)
	{
		tmp = LIST(list);
		ft_dlstreverse(&tmp);
		list->content = tmp;
		list = list->next;
	}
}

t_dlist	*solve(t_dlist *list, t_room *start, t_room *end, unsigned nbant)
{
	t_dlist	*result;
	size_t	maxpath;
	t_room	*begin;
	t_room *goal;

	begin = (ft_dlstlen(start->neighbours) <= ft_dlstlen(end->neighbours)) ?
		start : end;
	goal = (begin == start) ? end : start;
	maxpath = ft_dlstlen(begin->neighbours);
	prepare(list, begin, goal);
	result = get_path(list, begin, goal, nbant);
	// refaire la fonction qui reverse les listes parce qu'elle fait sauter le premier maillon
	// if (begin == end)
	// 	ft_dlstreverse(&result);
	// ft_printf("result = %p\n", result);
	return (result);
}
