/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:50:46 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/28 20:18:39 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include "ft_string.h"
# include "dlst.h"
# include "get_next_line.h"
# include "conversion.h"
# include "ft_printf.h"

typedef struct			s_room
{
	unsigned int		cost;
	unsigned char	occupied;
	char				*name;
	unsigned int		x;
	unsigned int		y;
	char					in;
	t_dlist				*neighbours;
	t_dlist				*removed;
}						t_room;

# define	ROOM(x) ((t_room *)x->content)
# define	LIST(x) ((t_dlist *)x->content)

/*
** Graph related functions
*/

t_room					*find_room(t_dlist *head, char *name);

int						is_connected(t_room *start, t_room *end);
void					rm(t_dlist *tmp, t_room *room);
void					disconnect(t_room *room);
void					reconnect(t_dlist *elem);

void					free_room(void *room, size_t room_size);
int						room_cmp(const void *s1, const void *s2);
t_room					*find_double(t_dlist *p1, t_dlist *p2);
void						prepare(t_dlist *list, t_room *begin, t_room *goal);
t_dlist					*get_max(t_dlist *list);

/*
** Parsing related functions
*/

int						is_comment(const char *line);
int						is_command(const char *line);
int						is_room(const char *line);
int						is_valid_connexion(t_dlist *list, char *line);

void					comment(char *line);
t_dlist					*parse(t_room **start, t_room **end);

/*
** Solving related functions
*/

t_dlist				*solve(t_dlist *list, t_room *start, t_room *end, unsigned nbant);
void					addend(t_dlist *result, t_room *end);

void					lem_in(t_dlist *list, t_dlist *result, unsigned int nbant, t_room *start, t_room *end);

/*
** Output functions
*/

void					print_path(t_dlist *elem);
void					print_room(t_dlist *room);
void					print_elem(t_dlist *elem);


/*
** Algo
*/

void					dijkstra(t_dlist *nodes, t_room *start);
t_dlist					*path_finding(
									t_dlist *nodes,
									t_room *start,
									t_room *end);
size_t						score_it(t_dlist *route, unsigned int nbant);
void						generate(size_t i, t_room *tab[]);
t_room					*path_cmp(t_dlist *l1, t_dlist *l2);

#endif
