/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_connected.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:54:05 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 14:10:29 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lst.h"

int		recursion(t_list **lst, t_room *curr, t_room *goal)
{
	t_list	*walk;

	if (curr == goal)
		return (1);
	ft_lstadd(lst, ft_lstlink(curr, sizeof(curr)));
	walk = curr->neighbours;
	while (walk)
	{
		if (!find_room(*lst, ((t_room *)walk->content)->name))
		{
			if (recursion(lst, (t_room *)walk->content, goal))
				return (1);
		}
		walk = walk->next;
	}
	return (0);
}

int		is_connected(t_room *start, t_room *end)
{
	t_list	*history;
	int		ret;

	history = NULL;
	ret = recursion(&history, start, end);
	ft_lstdel(&history, NULL);
	return (ret);
}
