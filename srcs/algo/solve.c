/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/18 15:33:46 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	t_room	*goal;

	begin = (ft_dlstlen(start->neighbours) <= ft_dlstlen(end->neighbours)) ?
		start : end;
	goal = (begin == start) ? end : start;
	prepare(list, begin, goal);
	result = get_path(list, begin, goal, nbant);
	if (begin == end)
		ft_dlstiter(result, reverseall);
	return (result);
}
