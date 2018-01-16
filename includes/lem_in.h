/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:50:46 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/16 20:11:04 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <unistd.h>
#include <stdlib.h>

struct					s_room;

typedef struct			s_roomlist
{
	struct	s_room		*room;
	struct	s_roomlist	*next;
	struct	s_roomlist	*prev;
}						t_roomlist;

typedef struct			s_room
{
	char				*name;
	unsigned int		x;
	unsigned int		y;
	struct s_roomlist	*neighbours;
}						t_room;

/*
** Graph related functions
*/

t_room					*new_room(char *name, unsigned int x, unsigned int y);
t_room					*find_room(t_roomlist *head, char *name);

t_roomlist				*new_elem(t_room *room);
void					del_list(t_roomlist **head);
void					add_elem(t_roomlist **head, t_roomlist *elem);
void					add_back(t_roomlist **head, t_roomlist *elem);

int						connected(t_room *start, t_room *end);

void					rotate(t_roomlist **head);
void					r_rotate(t_roomlist **head);

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

/*
** Utility functions
*/

int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *src);
char					*ft_strnew(size_t size);
void					*ft_memalloc(size_t size);

#endif
