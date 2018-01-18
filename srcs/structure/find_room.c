/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:33:09 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/18 11:30:52 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lst.h"
#include "ft_string.h"

t_room	*find_room(t_list *head, char *name)
{
	while (head)
	{
		if (ft_strcmp(((t_room *)head->content)->name, name) == 0)
			return (head->content);
		head = head->next;
	}
	return (NULL);
}
