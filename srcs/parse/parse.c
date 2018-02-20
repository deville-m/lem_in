/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:48:41 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/20 20:41:12 by mdeville         ###   ########.fr       */
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
	res.in = 0;
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
	free(line);
	if (command == 3)
		return ;
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
			free(line);
	}
	parse_connexions(list, line);
	return (list);
}
