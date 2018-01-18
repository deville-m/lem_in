/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:48:41 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/18 19:34:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "lst.h"
#include "ft_string.h"
#include "conversion.h"
#include "get_next_line.h"
#include "ft_printf.h"

static void			parse_room(t_list **list, char *line)
{
	t_room	res;
	size_t	i;

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
	ft_lstadd(list, ft_lstnew(&res, sizeof(res)));
}

static void			parse_command(
							t_list **list,
							char *line,
							t_room **start,
							t_room **end)
{
	int command;

	command = is_command(line);
	free(line);
	while (get_next_line(0, &line) == 1 && is_comment(line))
		free(line);
	if (is_room(line))
	{
		parse_room(list, line);
		free(line);
		if (command == 1)
			*start = (t_room *)(*list)->content;
		else if (command == 2)
			*end = (t_room *)(*list)->content;
	}
}

static void			parse_connexion(t_list *list, char *line)
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
	ft_lstadd(&tmp1->neighbours, ft_lstlink(tmp2, sizeof(t_room)));
	ft_lstadd(&tmp2->neighbours, ft_lstlink(tmp1, sizeof(t_room)));
}

static inline int	first_line(t_list *list, char *line)
{
	static int norm = 0;

	if (norm)
		return (norm);
	if (is_comment(line))
	{
		free(line);
		norm = 1;
	}
	else if (is_valid_connexion(list, line))
	{
		parse_connexion(list, line);
		free(line);
		norm = 1;
	}
	return (norm);
}

t_list				*parse(t_room **start, t_room **end)
{
	t_list	*list;
	int		ret;
	char	*line;

	list = NULL;
	while (get_next_line(0, &line) == 1
			&& ((ret = is_room(line)) || *line == '#'))
	{
		if (ret)
			parse_room(&list, line);
		else if (is_command(line))
			parse_command(&list, line, start, end);
		else
			free(line);
	}
	while (first_line(list, line) && get_next_line(0, &line) == 1
			&& ((ret = is_valid_connexion(list, line)) || is_comment(line)))
	{
		if (ret)
			parse_connexion(list, line);
		else
			free(line);
	}
	free(line);
	return (list);
}
