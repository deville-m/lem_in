/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disconnect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:34:32 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/18 15:41:20 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	rm(t_dlist *tmp, t_room *room)
{
	t_dlist	*prev;
	t_dlist	*tmp2;

	prev = NULL;
	tmp2 = ROOM(tmp)->neighbours;
	while (tmp2)
	{
		if (ROOM(tmp2) == room)
		{
			if (prev)
				prev->next = tmp2->next;
			else
				ROOM(tmp)->neighbours = tmp2->next;
			ft_dlstprepend(&ROOM(tmp)->removed, tmp2);
			break ;
		}
		prev = tmp2;
		tmp2 = tmp2->next;
	}
}

void	disconnect(t_room *room)
{
	t_dlist	*tmp;

	if (!room)
		return ;
	tmp = room->neighbours;
	while (tmp)
	{
		rm(tmp, room);
		tmp = tmp->next;
	}
}
