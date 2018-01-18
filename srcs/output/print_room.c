/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 00:20:18 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 00:35:05 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"
#include "lst.h"

void	print_room(t_list *elem)
{
	t_list *list;

	ft_printf("%s:\n", ((t_room *)elem->content)->name);
	list = ((t_room *)elem->content)->neighbours;
	while (list)
	{
		ft_printf("  %s\n", ((t_room *)list->content)->name);
		list = list->next;
	}
	ft_printf("\n");
}
