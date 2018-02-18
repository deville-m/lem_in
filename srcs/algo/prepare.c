/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:20:06 by vlay              #+#    #+#             */
/*   Updated: 2018/02/18 15:20:09 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	deleteneigh(t_room *room)
{
	t_dlist	*cmp;
	t_dlist *tmp;

	tmp = room->neighbours;
	while (tmp)
	{
		cmp = room->neighbours;
		while (cmp)
		{
			rm(tmp, ROOM(cmp));
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
}

void	prepare(t_dlist *list, t_room *begin, t_room *goal)
{
	deleteneigh(begin);
	deleteneigh(goal);
	dijkstra(list, begin);
}
