/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reconnect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:53:53 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 22:04:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reconnect(t_list *elem)
{
	t_list	*tmp;

	if (!elem)
		return ;
	tmp = ROOM(elem)->removed;
	if (!tmp)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ROOM(elem)->neighbours;
	ROOM(elem)->neighbours = ROOM(elem)->removed;
	ROOM(elem)->removed = NULL;
}
