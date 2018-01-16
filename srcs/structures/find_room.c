/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:53:45 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/16 19:46:00 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_room(t_roomlist *head, char *name)
{
	t_roomlist *curr;

	if (!head)
		return (NULL);
	curr = head;
	while (1)
	{
		if (ft_strcmp(curr->room->name, name))
			return (curr->room);
		curr = curr->next;
		if (curr == head)
			break ;
	}
	return (NULL);
}
