/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:51:17 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 18:47:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

static inline void	ba(t_dlist *e1, t_dlist *e2)
{
	e2->next = e1->next;
	e1->prev = e2->prev;
	if (e1->next)
		e1->next->prev = e2;
	if (e2->prev)
		e2->prev->next = e1;
	e1->next = e2;
	e2->prev = e1;
}

static inline void	ab(t_dlist *e1, t_dlist *e2)
{
	e1->next = e2->next;
	e2->prev = e1->prev;
	if (e2->next)
		e2->next->prev = e1;
	if (e1->prev)
		e1->prev->next = e2;
	e2->next = e1;
	e1->prev = e2;
}

void				ft_dlstswap(t_dlist *e1, t_dlist *e2)
{
	t_dlist *tmp;

	if (!e1 || !e2 || e1 == e2)
		return ;
	if (e1->next == e2)
		ab(e1, e2);
	else if (e2->next == e1)
		ba(e1, e2);
	else
	{
		if (e2->prev)
			e2->prev->next = e1;
		if (e2->next)
			e2->next->prev = e1;
		if (e1->prev)
			e1->prev->next = e2;
		if (e1->next)
			e1->next->prev = e2;
		tmp = e1->next;
		e1->next = e2->next;
		e2->next = tmp;
		tmp = e1->prev;
		e1->prev = e2->prev;
		e2->prev = tmp;
	}
}
