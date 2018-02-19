/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:59 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/19 23:49:14 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t			possible(t_dlist *past, t_room *curr)
{
	size_t	i;
	t_dlist	*tmp;

	tmp = curr->neighbours;
	i = 0;
	while (tmp)
	{
		if (!find_room(past, ROOM(tmp)->name))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_dlist			*find_min(t_room *room,
				t_dlist *past, t_room *start, size_t limits)
{
	t_dlist *min;
	t_dlist *tmp;

	min = room->neighbours;
	if (ROOM(min) == start)
		return (min);
	while (min && ROOM(min) != start
		&& (find_room(past, ROOM(min)->name)
		|| ROOM(min)->occupied > limits))
		min = min->next;
	tmp = (min) ? min->next : NULL;
	while (tmp)
	{
		if (ROOM(tmp) == start)
			return (tmp);
		if ((ROOM(tmp)->occupied <= limits
			&& ROOM(tmp)->cost < ROOM(min)->cost
			&& !find_room(past, ROOM(tmp)->name)))
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static	t_dlist	*get_next(t_room *room, t_dlist *past, t_room *start)
{
	size_t	limits;
	t_dlist *min;

	limits = 0;
	if (!possible(past, room))
		return (NULL);
	while (1)
	{
		min = find_min(room, past, start, limits);
		if (min && ROOM(min) == start)
			return (min);
		if (past && min && find_room(past, ROOM(min)->name))
			min = NULL;
		if (min && ROOM(min)->occupied <= limits)
			break ;
		limits++;
	}
	return (min);
}

void			last_res(t_dlist **res)
{
	if (*res && ft_dlstlen(*res))
	{
		ft_dlstpop(res);
		if (!*res)
			ft_dlstprepend(res, ft_dlstlink(NULL, sizeof(t_dlist *)));
	}
}

t_dlist			*path_finding(t_dlist *list, t_room *start, t_room *end)
{
	t_dlist	*res;
	t_dlist	*tmp;

	if (!list || !start || !end)
		return (NULL);
	res = NULL;
	disconnect(end);
	while (end != start)
	{
		tmp = get_next(end, res, start);
		if (!tmp)
		{
			ft_dlstdel(&res, NULL);
			break ;
		}
		ROOM(tmp)->occupied++;
		ft_dlstprepend(&res, ft_dlstlink(ROOM(tmp), sizeof(end)));
		end = ROOM(tmp);
	}
	last_res(&res);
	return (res);
}
