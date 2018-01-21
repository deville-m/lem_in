/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/21 21:27:20 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	congestion(t_list *path)
{
	while (path)
	{
		disconnect(ROOM(path));
		path = path->next;
	}
}

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

// t_list	*get_path(t_list *list, t_room *begin, t_room *goal)
// {
// 	t_list	*tmp;
// 	t_list	*result;
//
// 	tmp = begin->neighbours;
// 	result = NULL;
// 	while (tmp)
// 	{
// 		ft_lstadd(&result,
// 				ft_lstlink(path_finding(list, ROOM(tmp), goal), sizeof(t_room)));
// 		tmp = tmp->next;
// 	}
// 	return (result);
// }

t_list	*get_path(t_list *list, t_room *begin, t_room *goal)
{
	size_t	score;
	t_list	*try;
	t_list	*find;
	t_list	*best;
	t_list	*tmp;
	t_list	*result;

	try = begin->neighbours;
	best = NULL;
	while (try)
	{
		result = NULL;
		tmp = begin->neighbours;
		while (tmp)
		{
			if ((find = path_finding(list, ROOM(tmp), goal)))
			{
				if (result)
					score = score_it(result, 1);
				ft_lstadd(&result,
					ft_lstlink(find, sizeof(t_room)));
				if (score < score_it(result, 1))
					free(ft_lstpop(&result));
				congestion(find);
			}
			tmp = tmp->next;
		}
		best = (!best) ? result : (score_it(result, 1) < score_it(best, 1)) ? result : best;
		disconnect(begin);
		ft_lstiter(list, reconnect);
		try = try->next;
	}
	return (best);
}

t_list	*solve(t_list *list, t_room *start, t_room *end)
{
	t_list	*result;
	size_t	maxpath;
	t_room	*begin;

	result = NULL;
	begin = (ft_lstlen(start->neighbours) <= ft_lstlen(end->neighbours)) ?
		start : end;
	ft_printf("BEGIN = %s | len start = %d | len end = %d\n", (begin == start) ? "start" : "end", ft_lstlen(start->neighbours), ft_lstlen(end->neighbours));
	maxpath = ft_lstlen(begin->neighbours);
	disconnect(begin);
	result = get_path(list, begin, (begin == start) ? end : start);
	return (result);
}
