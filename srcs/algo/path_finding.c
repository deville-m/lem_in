/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:59 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/21 19:36:51 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_dlist	*get_next(t_room *end)
{
	t_dlist *tmp;

	tmp = end->neighbours;
	while (tmp && ROOM(tmp)->cost != end->cost - 1)
		tmp = tmp->next;
	return (tmp);
}

t_dlist					*path_finding(t_dlist *list, t_room *start, t_room *end)
{
	t_room	*goal;
	t_dlist	*res;
	t_dlist	*tmp;

	if (!list || !start || !end)
		return (NULL);
	res = NULL;
	goal = end;
	dijkstra(list, start);
	while (end != start)
	{
		tmp = get_next(end);
		if (!tmp)
		{
			ft_dlstdel(&res, NULL);
			break ;
		}
		if (end != goal)
			ft_dlstprepend(&res, ft_dlstlink(end, sizeof(end)));
		end = ROOM(tmp);
	}
	if (end == start)
		ft_dlstprepend(&res, ft_dlstlink(end, sizeof(end)));
	return (res);
}
