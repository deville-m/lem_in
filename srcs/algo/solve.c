/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/17 18:25:51 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

size_t	mapcomplete(t_dlist *list, t_room *begin, t_room *goal)
{
	size_t	len;
	size_t	i;
	t_dlist	*tmp;

	tmp = list;
	i = 0;
	len = ft_dlstlen(list);
	while (tmp)
	{
		if (ROOM(tmp)->occupied >= len)
			return (1);
		if (ROOM(tmp) != begin && ROOM(tmp) != goal && ROOM(tmp)->occupied > 1)
			i++;
		tmp = tmp->next;
	}
	return ((i >= len - 2) ? 1 : 0);
}

t_dlist	*get_path(t_dlist *list, t_room *begin, t_room *goal, unsigned nbant)
{
	t_dlist	*path;
	t_dlist	*try;
	t_dlist	*best;
	t_dlist	*group;
	size_t	pick;
	size_t	maxpath;

	best = NULL;
	try = NULL;
	pick = 0;
	maxpath = (ft_dlstlen(begin->neighbours) > nbant) ? nbant : ft_dlstlen(begin->neighbours);
	while (!best || (ft_dlstlen(best) < maxpath && !mapcomplete(list, begin, goal)))
	{
		if ((path = path_finding(list, begin, goal)))
		{
			if (!alreadyfound(try, path))
			{
				ft_dlstprepend(&try, ft_dlstlink(path, sizeof(*try)));
				pick = 0;
			}
			else
			{
				pick++;
				free_path(path, sizeof(*path));
			}
		}
		if (pick > ft_dlstlen(begin->neighbours))
			break ;
		// ft_dlstiter(list, print_room);
		ft_printf("path : \n");
		ft_dlstiter(try, print_path);
		if (score_it((group = group_up(try)), nbant) < score_it(best, nbant))
		{
			ft_dlstdel(&best, free_path);
			best = ft_dlstdup(group);
		}
		ft_dlstdel(&group, NULL);
		ft_printf("best : \n");
		ft_dlstiter(best, print_path);
	}
	ft_dlstdel(&try, free_path);
	return (best);
}

void	reverseall(t_dlist *list)
{
	t_dlist	*tmp;

	while (list)
	{
		tmp = LIST(list);
		ft_dlstreverse(&tmp);
		list->content = tmp;
		list = list->next;
	}
}

t_dlist	*solve(t_dlist *list, t_room *start, t_room *end, unsigned nbant)
{
	t_dlist	*result;
	t_room	*begin;
	t_room *goal;

	begin = (ft_dlstlen(start->neighbours) <= ft_dlstlen(end->neighbours)) ?
		start : end;
	goal = (begin == start) ? end : start;
	prepare(list, begin, goal);
	result = get_path(list, begin, goal, nbant);
	if (begin == end)
		ft_dlstiter(result, reverseall);
	return (result);
}
