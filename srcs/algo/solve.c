/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/20 15:19:12 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_double(t_list **list, t_list *result)
{
	t_list	*tmp;
	t_list	*neighbours;

	tmp = *list;
	while (tmp)
	{
		neighbours = ROOM(tmp)->neighbours;
		ft_lstremove(list, )
		tmp = tmp->next;
	}
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
	t_list	*result;
	size_t	maxpath;
	t_room	*begin;

	result = NULL;
	begin = (ft_lstlen(start->neighbours) <= ft_lstlen(end->neighbours)) ?
		start : end;
	maxpath = ft_lstlen(begin->neighbours);
	get_path(list, begin, (begin == start) ? end : start, &result);
	return (result);
}
