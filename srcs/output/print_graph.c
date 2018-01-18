/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:02:44 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/18 19:34:36 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lst.h"
#include "ft_printf.h"

void	print_room(t_room *room)
{
	t_room	*tmp;
	t_list	*list;

	ft_printf("%s:\n", room->name);
	list = room->neighbours;
	while (list)
	{
		tmp = (t_room *)list->content;
		ft_printf("\t%s\n", tmp->name);
		list = list->next;
	}
}

void	print_graph(t_list *list)
{
	while (list)
	{
		print_room((t_room *)list->content);
		list = list->next;
	}
}
