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

static inline t_list	*get_next(t_room *end)
{
	t_list *tmp;

	tmp = end->neighbours;
	while (tmp && ROOM(tmp)->cost != end->cost - 1)
		tmp = tmp->next;
	return (tmp);
}

t_list					*path_finding(t_list *list, t_room *start, t_room *end)
{
	t_room	*goal;
	t_list	*res;
	t_list	*tmp;

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
			ft_lstdel(&res, NULL);
			break ;
		}
		if (end != goal)
			ft_lstadd(&res, ft_lstlink(end, sizeof(end)));
		end = ROOM(tmp);
	}
	if (end == start)
		ft_lstadd(&res, ft_lstlink(end, sizeof(end)));
	return (res);
}
