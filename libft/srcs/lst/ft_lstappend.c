#include "lst.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}
