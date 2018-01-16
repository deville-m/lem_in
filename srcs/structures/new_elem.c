/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:52:07 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/16 19:36:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

t_roomlist			*new_elem(t_room *room)
{
	t_roomlist *res;

	if (!(res = (t_roomlist *)malloc(sizeof(t_roomlist))))
		return (NULL);
	res->room = room;
	return (res);
}
