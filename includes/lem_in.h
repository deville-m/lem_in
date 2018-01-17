/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:50:46 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/17 22:52:38 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <unistd.h>
#include "libft/lst.h"

typedef struct			s_room
{
	char				*name;
	unsigned int		x;
	unsigned int		y;
	t_list				*neighbours;
}						t_room;

/*
** Graph related functions
*/

t_room					*new_room(char *name, unsigned int x, unsigned int y);
t_room					*find_room(t_list *head, char *name);

int						connected(t_room *start, t_room *end);

/*
** Parsing related functions
*/

t_roomlist				*parse_room(t_room **start, t_room **end);
void					parse_connexion(
										t_roomlist *list,
										t_room *start,
										t_room *end);

/*
** Solving related functions
*/

void					lem_in(
								t_roomlist *list,
								t_room *start,
								t_room *end);

#endif
