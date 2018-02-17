/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:48:41 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/17 14:47:20 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "lem_in.h"

static void			parse_room(t_dlist **list, char *line)
{
	char	*to_free;
	t_room	res;
	size_t	i;

	to_free = line;
	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	res.name = ft_strdup(line);
	line += i + 1;
	res.x = ft_atou(line);
	while (*line != ' ')
		line++;
	res.y = ft_atou(line);
	res.neighbours = NULL;
	res.removed = NULL;
	res.occupied = 0;
	ft_dlstprepend(list, ft_dlstnew(&res, sizeof(res)));
	free(to_free);
}

static void			parse_command(
							t_dlist **list,
							char *line,
							t_room **start,
							t_room **end)
{
	int command;

	command = is_command(line);
	if (command == 3)
		return ;
	free(line);
	while (get_next_line(0, &line) == 1 && logger(line, 0)
		&& (is_comment(line) || is_command(line) == 3))
		free(line);
	if (is_room(line))
	{
		parse_room(list, line);
		if (command == 1)
			*start = (t_room *)(*list)->content;
		else if (command == 2)
			*end = (t_room *)(*list)->content;
	}
}

static void			parse_connexion(t_dlist *list, char *line)
{
	t_room	*tmp1;
	t_room	*tmp2;
	char	*first;

	first = line;
	while (*line)
		line++;
	line += 1;
	tmp1 = find_room(list, first);
	tmp2 = find_room(list, line);
	ft_dlstprepend(&tmp1->neighbours, ft_dlstlink(tmp2, sizeof(t_room)));
	ft_dlstprepend(&tmp2->neighbours, ft_dlstlink(tmp1, sizeof(t_room)));
	free(first);
}

static inline int	first_line(t_dlist *list, char *line)
{
	static int norm = 0;

	if (norm)
		return (norm);
	else if (is_valid_connexion(list, line))
	{
		logger(line, 0);
		parse_connexion(list, line);
		norm = 1;
	}
	return (norm);
}

t_dlist				*parse(t_room **start, t_room **end)
{
	t_dlist	*list;
	int		ret;
	char	*line;

	list = NULL;
	while (get_next_line(0, &line) == 1 && logger(line, 0)
			&& ((ret = is_room(line)) || *line == '#'))
	{
		if (ret)
			parse_room(&list, line);
		else if (is_command(line))
			parse_command(&list, line, start, end);
		else
			comment(line);
	}
	while (first_line(list, line) && get_next_line(0, &line) == 1 && logger(line, 0)
			&& ((ret = is_valid_connexion(list, line)) || is_comment(line)))
	{
		if (ret)
			parse_connexion(list, line);
		else
			comment(line);
	}
	free(line);
	return (list);
}
