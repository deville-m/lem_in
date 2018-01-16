/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:49:28 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/16 19:30:55 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_elem(t_roomlist **head, t_roomlist *elem)
{
	if (!head || !elem)
		return ;
	if (!*head)
	{
		elem->next = elem;
		elem->prev = elem;
	}
	else
	{
		elem->next = *head;
		elem->prev = (*head)->prev;
		(*head)->prev->next = elem;
		(*head)->prev = elem;
	}
	*head = elem;
}
