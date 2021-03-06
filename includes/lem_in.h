/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:21:59 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/20 20:39:11 by mdeville         ###   ########.fr       */
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
# define ROOM(x) ((t_room *)x->content)
# define LIST(x) ((t_dlist *)x->content)

typedef struct					s_room
{
	unsigned long long int		cost;
	unsigned char				occupied;
	char						*name;
	unsigned int				x;
	unsigned int				y;
	char						in;
	t_dlist						*neighbours;
	t_dlist						*removed;
}								t_room;

/*
** Graph related functions
*/

t_room							*find_room(t_dlist *head, char *name);

int								is_connected(t_room *start, t_room *end);
void							rm(t_dlist *tmp, t_room *room);
void							disconnect(t_room *room);
void							reconnect(t_dlist *elem);

void							free_room(void *room, size_t room_size);
int								room_cmp(const void *s1, const void *s2);
t_room							*find_double(t_dlist *p1, t_dlist *p2);
void							prepare(t_dlist *list, t_room *begin,
								t_room *goal);
t_dlist							*get_max(t_dlist *list);
void							free_path(void *elem, size_t	size);
void							free_best(t_dlist *src);

/*
** Parsing related functions
*/

int								logger(char *line, int mode);
int								is_comment(const char *line);
int								is_command(const char *line);
int								is_room(const char *line);
int								is_valid_connexion(t_dlist *list, char *line);

void							parse_connexions(t_dlist *list, char *line);
t_dlist							*parse(t_room **start, t_room **end);

/*
** Solving related functions
*/
void							prepare(t_dlist *list,
								t_room *begin, t_room *goal);
t_dlist							*solve(t_dlist *list, t_room *start,
								t_room *end, unsigned nbant);
void							addend(t_dlist *result, t_room *end);

void							lem_in(t_dlist *result, unsigned int nbant,
								t_room *start, t_room *end);
t_dlist							*group_up(t_dlist *try);
t_room							*path_cmp(t_dlist *l1, t_dlist *l2);
size_t							alreadyfound(t_dlist *list, t_dlist *path);
t_dlist							*get_path(t_dlist *list, t_room *begin,
								t_room *goal, unsigned nbant);

/*
** Output functions
*/

void							print_path(t_dlist *elem);
void							print_room(t_dlist *room);
void							print_elem(t_dlist *elem);

/*
** Algo
*/

void							dijkstra(t_dlist *nodes, t_room *start);
t_dlist							*path_finding(
									t_dlist *nodes,
									t_room *start,
									t_room *end);
size_t							score_it(t_dlist *route, unsigned int nbant);
void							generate(size_t i, t_room *tab[]);
t_room							*path_cmp(t_dlist *l1, t_dlist *l2);
t_dlist							*get_max(t_dlist *list);
t_dlist							*ft_dlstdup(t_dlist *src);
void							apply(t_dlist *antloc[], t_room *end);
char							**ft_tabcpy(char **tab, size_t hauteur);
size_t							ft_tabheight(char **tab);
void							ft_tabdel(char **tab);
size_t							ft_strclen(const char *str, int c);

#endif
