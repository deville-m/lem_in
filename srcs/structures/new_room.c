/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:03:58 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/16 20:09:48 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(char *name, unsigned int x, unsigned int y)
{
	char	*dup;
	t_room	*res;

	if (!(res = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (!(dup = ft_strdup(name)))
	{
		free(res);
		return (NULL);
	}
	res->name = dup;
	res->x = x;
	res->y = y;
	res->neighbours = NULL;
	return (res);
}
