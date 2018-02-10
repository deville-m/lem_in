/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:30:55 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/10 16:44:42 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

t_dlist	*get_max(t_dlist *list)
{
	t_dlist	*max;

	max = NULL;
	while (list)
	{
		if (!max || ft_dlstlen(LIST(list)) > ft_dlstlen(max))
			max = LIST(list);
		list = list->next;
	}
	return (max);
}

size_t	score_it(t_dlist *route, unsigned int nbant)
{
	size_t	plus;
	size_t	maxlen;
	t_dlist	*list;

	if (!(list = route) || !ft_dlstlen(route))
		return (UINT_MAX);
	list = route;
	maxlen = ft_dlstlen(get_max(list));
	while (list)
	{
		if (nbant > maxlen - ft_dlstlen(LIST(list)))
			nbant -= maxlen - ft_dlstlen(LIST(list));
		else
			nbant = 0;
		list = list->next;
	}
	plus = (nbant % ft_dlstlen(route)) ? 1 : 0;
	return (maxlen + (nbant / ft_dlstlen(route)) + plus);
}
