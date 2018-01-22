#include "lem_in.h"
#include <limits.h>

void	init_deter(t_room *begin, t_room *except)
{
	t_list	*tmp;

	if (!begin)
		return ;
	tmp = begin->neighbours;
	begin->cost = INT_MAX;
	while (tmp)
	{
		if (ROOM(tmp) != except)
			ROOM(tmp)->cost = INT_MAX;
		tmp = tmp->next;
	}
}

void	deter(t_list *path)
{
	while (path)
	{
		ROOM(path)->cost = INT_MAX;
		path = path->next;
	}
}
