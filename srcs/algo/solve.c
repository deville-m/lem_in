/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/21 16:14:53 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*compare 2 path et return la room qu'ils ont en commun */

t_room	*path_cmp(t_list *l1, t_list *l2)
{
	t_list	*p1;
	t_list	*p2;

	if (!l1 || !l2 || !LIST(l1) || !LIST(l2))
		return (NULL);
	p1 = LIST(l1);
	while (p1)
	{
		p2 = LIST(l2)->next;
		while (p2)
		{
			if (p1->content == p2->content)
				return (ROOM(p1));
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (NULL);
}

/* find_route return tout les groupes possible qu'il peut constituer avec l'ensemble des path qu'on lui donne en parametre */

t_list	*find_route(t_list *result)
{
	t_list	*tmp;
	t_list	*route;

	if (!result)
		return (NULL);
	route = NULL;
	while (result->next)
	{
		tmp = result->next;
		result = result->next;
	}
	return (NULL);
}

t_room	*find_double(t_list *p1, t_list *p2)
{
	t_list	*origin;

	origin = p2;
	while (p1)
	{
		p2 = origin;
		while (p2)
		{
			if (p2->content == p1->content)
				return (ROOM(p1));
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (NULL);
}

size_t	get_path(t_list *list, t_room *begin, t_room *goal, t_list **result)
{
	size_t	i;
	t_list	*tmp;

	tmp = begin->neighbours;
	i = 0;
	while (tmp)
	{
		ft_lstadd(result,
				ft_lstlink(path_finding(list, ROOM(tmp), goal), sizeof(t_room)));
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_list	*solve(t_list *list, t_room *start, t_room *end)
{
	t_room	*cmp;
	t_list	*result;
	size_t	maxpath;
	t_room	*begin;

	result = NULL;
	begin = (ft_lstlen(start->neighbours) <= ft_lstlen(end->neighbours)) ?
		start : end;
	maxpath = ft_lstlen(begin->neighbours);
	disconnect(begin);
	get_path(list, begin, (begin == start) ? end : start, &result);
	cmp = path_cmp(result, result->next);
	if (cmp)
		ft_printf("cmp = %s\n", cmp->name);
	return (result);
}
