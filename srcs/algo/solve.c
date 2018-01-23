/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/23 21:29:32 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*t_room	*path_cmp(t_dlist *l1, t_dlist *l2)
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

t_dlist	*find_route(t_dlist *result, int maxpath)
{
	t_dlist	*tmp;
	t_dlist	*route;

	if (!result)
		return (NULL);
	route = NULL;
	while (result->next)
	{
		tmp = result->next;
		result = result->next;
	}
	return (NULL);
}

t_dlist	*get_path(t_dlist *list, t_room *begin, t_room *goal)
{
	t_dlist	*tmp;
	t_dlist	*result;

	tmp = begin->neighbours;
	result = NULL;
	while (tmp)
	{
		ft_dlstprepend(&result,
				ft_dlstlink(path_finding(list, ROOM(tmp), goal), sizeof(t_room)));
		tmp = tmp->next;
	}
	return (result);
}*/

#include <stdio.h>

void	find_path(t_dlist **res, t_room *start, t_room *end)
{
	t_dlist	*tmp;
	t_dlist	*minlst;
	int		min;
	int		tmplen;;

	ft_dlstprepend(res, ft_dlstlink(start, sizeof(start)));
	if (start == end)
		return ;
	tmp = start->neighbours;
	minlst = tmp;
	min = ft_dlstlen(ROOM(tmp)->neighbours);
	while (tmp)
	{
		tmplen = ft_dlstlen(ROOM(tmp)->neighbours);
		if ((tmplen < min || (tmplen == min && ROOM(minlst)->cost < ROOM(tmp)->cost))
				&& !find_room(*res, ROOM(tmp)->name))
		{
			min = tmplen;
			minlst = tmp;
		}
		tmp = tmp->next;
	}
	find_path(res, ROOM(minlst), end);
}

t_dlist	*get_path(t_room *begin, t_room *end)
{
	t_dlist	*result;
	t_dlist	*tmp;
	t_dlist	*restmp;

	result = NULL;
	tmp = begin->neighbours;
	while (tmp)
	{
		restmp = NULL;
		find_path(&restmp, ROOM(tmp), end);
		if (restmp)
			ft_dlstprepend(&result, ft_dlstlink(restmp, sizeof(t_dlist *)));
		tmp = tmp->next;
	}
	return (result);
}

void	prepare(t_dlist *list, t_room *begin, t_room *end)
{
	t_dlist *tmp;

	disconnect(begin);
	dijkstra(list, end);
	ft_dlstiter(list, print_room);
	/*tmp = begin->neighbours;
	while (tmp)
	{
		disconnect(ROOM(tmp));
		tmp = tmp->next;
	}*/
}

t_dlist	*solve(t_dlist *list, t_room *start, t_room *end)
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
	result = get_path(begin, goal);
	return (result);
}
