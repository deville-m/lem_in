/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:14:40 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 20:49:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lem_in.h"

static void	set_cost(t_list *elem)
{
	ROOM(elem)->cost = UINT_MAX;
}

static void	recursion(t_room *curr)
{
	t_list *walk;

	walk = curr->neighbours;
	while (walk)
	{
		if (curr->cost + 1 < ROOM(walk)->cost)
		{
			ROOM(walk)->cost = curr->cost + 1;
			recursion(ROOM(walk));
		}
		walk = walk->next;
	}
}

void		dijkstra(t_list *nodes, t_room *start)
{
	if (!start)
		return ;
	ft_lstiter(nodes, set_cost);
	start->cost = 0;
	recursion(start);
}
