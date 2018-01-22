/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:59 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 21:21:23 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*path_finding(t_list *list, t_room *start, t_room *end)
{
	t_room	*max;
	t_room	*goal;
	t_list	*res;
	t_list	*tmp;

	if (!list || !start || !end)
		return (NULL);
	res = NULL;
	goal = end;
	while (end != start)
	{
		max = NULL;
		tmp = end->neighbours;
		while (tmp)
		{
			if ((!max || max->cost < ROOM(tmp)->cost) && ROOM(tmp)->cost < end->cost)
				max = ROOM(tmp);
			tmp = tmp->next;
		}
		if (!max)
		{
			ft_lstdel(&res, NULL);
			break ;
		}
		if (end != goal)
			ft_lstadd(&res, ft_lstlink(end, sizeof(end)));
		end = max;
	}
	if (end == start)
		ft_lstadd(&res, ft_lstlink(end, sizeof(end)));
	return (res);
}
