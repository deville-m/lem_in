#include "lem_in.h"

void	ft_init_cost(t_list *list)
{
	while(list)
	{
		ROOM(list)->cost = 0;
		list = list->next;
	}
}

void	ft_cost_it(t_list *list, t_room *end)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ROOM(tmp) != end)
		{
			if (!ROOM(tmp)->cost)
				ROOM(tmp)->cost = ROOM(list)->cost + 1;
			else if (ROOM(tmp)->cost > ROOM(list)->cost + 1)
				ROOM(tmp)->cost = ROOM(list)->cost + 1;
		}
		tmp = tmp->next;
	}
	tmp = ROOM(list)->neighbours;
	while (tmp)
	{
		ft_cost_it(tmp, end);
		tmp = tmp->next;
	}
}

void	ft_get_cost(t_list *list, t_room *end)
{
	ft_init_cost(list);
	ft_cost_it(list, end);
}
