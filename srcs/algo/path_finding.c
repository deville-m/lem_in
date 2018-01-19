/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:59 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 21:22:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*path_finding(t_list *list, t_room *start, t_room *end)
{
	t_list *res;
	t_list *tmp;

	if (!list || !start || !end)
		return (NULL);
	res = NULL;
	dijkstra(list, start);
	while (end != start)
	{
		tmp = end->neighbours;
		while (tmp && ROOM(tmp)->cost != end->cost - 1)
		{
			tmp = tmp->next;
		}
		if (!tmp)
		{
			ft_lstdel(&res, NULL);
			break ;
		}
		ft_lstadd(&res, ft_lstlink(end, sizeof(end)));
		end = ROOM(tmp);
	}
	if (end == start)
		ft_lstadd(&res, ft_lstlink(end, sizeof(end)));
	return (res);
}
