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
