/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alreadyfound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:17:46 by vlay              #+#    #+#             */
/*   Updated: 2018/02/18 15:17:49 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	already(t_dlist *l1, t_dlist *l2)
{
	if (!l1 || !l2)
		return (0);
	while (l1 && l2)
	{
		if (ROOM(l1) != ROOM(l2))
			return (0);
		l1 = l1->next;
		l2 = l2->next;
	}
	return (1);
}

size_t	alreadyfound(t_dlist *list, t_dlist *path)
{
	t_dlist	*l;
	t_dlist *p;

	if (!list)
		return (0);
	while (list)
	{
		p = path;
		l = LIST(list);
		if (already(l, p))
			return (1);
		list = list->next;
	}
	return (0);
}
