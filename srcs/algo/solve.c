/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/27 22:18:36 by vlay             ###   ########.fr       */
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
		p2 = LIST(l2)->next;
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
			ft_printf("%s VS %s\n", ROOM(LIST(tmp))->name, ROOM(LIST(cmp))->name);
			matrice[j][i++] = (!path_cmp(tmp, cmp)) ? '1' : '0';
			cmp = cmp->next;
		}
		matrice[j++][i] = '\0';
		tmp = tmp->next;
	}
	matrice[j] = NULL;
	j = 0;
	while (matrice[j])
	{
		ft_printf("%s\n", matrice[j]);
		j++;
	}
	return (matrice);
}

t_dlist	*group_up(t_dlist *try)
{
	char	**cpy;
	char	**matrice;
	t_dlist	*group;

	group = NULL;
	matrice = combi(try);
	cpy = ft_tabcpy(matrice, ft_tabheight(matrice));
	return (group);
}

void	congestion(t_dlist *path)
{
	while (path)
	{
		ROOM(path)->occupied = 1;
		path = path->next;
	}
}

void	decongestion(t_dlist *list, t_room *begin)
{
	dijkstra(list, begin);
	while (list)
	{
		ROOM(list)->occupied = 0;
		list = list->next;
	}
}

t_dlist	*get_path(t_dlist *list, t_room *begin, t_room *goal, unsigned nbant, size_t maxpath)
{
	size_t	st;
	size_t	sb;
	t_dlist	*path;
	t_dlist	*try;
	t_dlist	*best;
	t_dlist	*current;

	best = NULL;
	try = NULL;
	while (!best && ft_dlstlen(best) < maxpath)
	{
		current = begin->neighbours;
		while (current)
		{
			if ((path = path_finding(list, begin, goal)))
			{
				ft_dlstprepend(&try, ft_dlstlink(path, sizeof(*try)));
				congestion(path);
			}
			current = current->next;
		}
		group_up(try);
		if ((st = score_it(try, nbant)) < (sb = score_it(best, nbant)))
		{
			ft_printf("score try = %zd | score best = %zd\n", st, sb);
			best = try;
		}
	}
	return (best);
}

void	prepare(t_dlist *list, t_room *begin, t_room *goal)
{
	// t_dlist *tmp;

	// disconnect(begin);
	dijkstra(list, begin);
	// ft_dlstiter(list, print_room);
	/*tmp = begin->neighbours;
	while (tmp)
	{
		disconnect(ROOM(tmp));
		tmp = tmp->next;
	}*/
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
	result = get_path(list, begin, goal, nbant, maxpath);
	// ft_printf("result = %p\n", result);
	return (result);
}
