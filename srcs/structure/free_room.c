/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:28:22 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/18 14:37:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "lst.h"

void	free_room(void *room, size_t size)
{
	t_list *tmp;

	if (!room)
		return ;
	(void)size;
	tmp = ((t_room *)room)->neighbours;
	ft_lstdel(&tmp, NULL);
	free(room);
}
