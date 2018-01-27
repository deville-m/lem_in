/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:59 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/27 22:22:03 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_dlist	*dpath_cmp(t_dlist *l1, t_dlist *l2)
{
	while (l1)
	{
		if (ROOM(l1) == ROOM(l2))
			return (l1);
		l1 = l1->next;
	}
	return (NULL);
}

static t_dlist	*get_next(t_room *room, t_dlist *past, t_room *end)
{
	t_dlist *tmp;
	t_dlist *min;

	min = room->neighbours;
	while (min && find_room(past, ROOM(min)->name))
		min = min->next;
	tmp = (min) ? min->next : NULL;
	while (tmp)
	{
		if (ROOM(tmp) == end)
			return (tmp);
		if (!ROOM(tmp)->occupied && ROOM(tmp)->cost < ROOM(min)->cost && !find_room(past, ROOM(min)->name))
			min = tmp;
		tmp = tmp->next;
	}
	if (min && ROOM(min)->occupied)
	{
		while (min && find_room(past, ROOM(min)->name))
			min = min->next;
		tmp = (min) ? min->next : NULL;
	}
	while (tmp)
	{
		if (ROOM(tmp) == end)
			return (tmp);
		if (ROOM(tmp)->cost < ROOM(min)->cost && !find_room(past, ROOM(min)->name))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_dlist					*path_finding(t_dlist *list, t_room *start, t_room *end)
{
	t_dlist	*next;
	t_room	*goal;
	t_dlist	*res;
	t_dlist	*tmp;

	if (!list || !start || !end)
		return (NULL);
	res = NULL;
	goal = end;
	disconnect(end);
	while (end != start)
	{
		ft_printf("end = %s\n", end->name);
		tmp = get_next(end, res, end);
		if (!tmp)
		{
			ft_dlstdel(&res, NULL);
			break ;
		}
		// if (end != goal)
		ft_dlstprepend(&res, ft_dlstlink(ROOM(tmp), sizeof(end)));
		end = ROOM(tmp);
	}
	next = (res) ? res->next : NULL;
	if (res)
		free(res);
	res = next;
	return (res);
}
