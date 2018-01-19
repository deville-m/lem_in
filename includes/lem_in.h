/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:50:46 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 18:29:19 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include "ft_string.h"
# include "lst.h"
# include "get_next_line.h"
# include "conversion.h"
# include "ft_printf.h"

typedef struct			s_room
{
	unsigned int		cost;
	char				*name;
	unsigned int		x;
	unsigned int		y;
	t_list				*neighbours;
}						t_room;

# define	ROOM(x) ((t_room *)x->content)

/*
** Graph related functions
*/

t_room					*find_room(t_list *head, char *name);

int						is_connected(t_room *start, t_room *end);

void					free_room(void *room, size_t room_size);
int						room_cmp(const void *s1, const void *s2);

/*
** Parsing related functions
*/

int						is_comment(const char *line);
int						is_command(const char *line);
int						is_room(const char *line);
int						is_valid_connexion(t_list *list, char *line);

t_list					*parse(t_room **start, t_room **end);

/*
** Solving related functions
*/

void					lem_in(
							t_list *list,
							t_room *start,
							t_room *end);

							void	ft_get_cost(t_list *list, t_room *end);

/*
** Output functions
*/

void					print_room(t_list *list);


/*
** Algo
*/

void					dijkstra(t_list *nodes, t_room *start);

#endif
