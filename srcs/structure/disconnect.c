/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disconnect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:34:32 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 21:48:16 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	disconnect(t_room *room, t_room *neigbour)
{
	t_list	*tmp;

	if (!room || !neigbour)
		return ;
	tmp = ft_lstremove(&neigbour->neighbours, room->name, room_cmp);
	if (!tmp)
		return ;
	ft_lstadd(&neigbour->removed, tmp);
}
