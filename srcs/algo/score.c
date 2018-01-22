#include "lem_in.h"

size_t	try_score(t_list *find, t_list *route, unsigned int nbant)
{
	size_t	score;
	t_list	*try;

	try = route;
	ft_lstadd(&route, find);
	score = score_it(try, nbant);
	find->next = NULL;
	return (score);
}

size_t	score_it(t_list *route, unsigned int nbant)
{
	size_t	plus;
	size_t	maxlen;
	t_list	*max;
	t_list	*list;

	max = NULL;
	list = route;
	while (list)
	{
		if (!max || ft_lstlen(LIST(list)) > ft_lstlen(max))
			max = LIST(list);
		list = list->next;
	}
	list = route;
	maxlen = ft_lstlen(max);
	while (list)
	{
		if (nbant > maxlen - ft_lstlen(LIST(list)))
			nbant -= maxlen - ft_lstlen(LIST(list));
		else
			nbant = 0;
		list = list->next;
	}
	plus = (nbant % ft_lstlen(route)) ? 1 : 0;
	return (maxlen + nbant / ft_lstlen(route));
}
