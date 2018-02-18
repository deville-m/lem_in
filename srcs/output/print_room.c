/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 00:20:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/18 15:42:35 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "lst.h"

void	print_room(t_dlist *elem)
{
	t_dlist *list;

	ft_printf("%s - %u | %u:\n", ((t_room *)elem->content)->name,
			ROOM(elem)->cost, ROOM(elem)->occupied);
	list = ((t_room *)elem->content)->neighbours;
	while (list)
	{
		ft_printf("  %s\n", ((t_room *)list->content)->name);
		list = list->next;
	}
	ft_printf("\n");
}
