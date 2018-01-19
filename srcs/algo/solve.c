/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:30:06 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 22:04:06 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*solve(t_list *list, t_room *start, t_room *end)
{
	t_list	*tmp;
	t_list *result;
	size_t	maxpath;
	t_room	*begin;

	result = NULL;
	begin = (ft_lstlen(start->neighbours) <= ft_lstlen(end->neighbours)) ?
		start : end;
	maxpath = ft_lstlen(begin->neighbours);
	tmp = begin->neighbours;
	maxpath = 0;
	while (tmp)
	{
		ft_lstadd(&result,
				ft_lstlink(path_finding(list, ROOM(tmp),
					(begin == start) ? end : start), sizeof(t_room)));
		tmp = tmp->next;
	}
	return (result);
}
