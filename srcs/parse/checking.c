/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 10:03:16 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/20 20:36:53 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_string.h"
#include "lst.h"

int		is_comment(const char *line)
{
	return (line
			&& *line == '#'
			&& *(line + 1) != '#');
}

int		is_command(const char *line)
{
	if (line && *line == '#' && *(line + 1) == '#')
	{
		if (!ft_strcmp(line + 2, "start"))
			return (1);
		if (!ft_strcmp(line + 2, "end"))
			return (2);
		return (3);
	}
	return (0);
}

int		is_room(const char *line)
{
	if (!line)
		return (0);
	while (*line && *line != ' ' && *line != 'L')
		line++;
	if (*line != ' ')
		return (0);
	line += 1;
	while (*line && *line >= '0' && *line <= '9')
		line++;
	if (*line != ' ')
		return (0);
	line += 1;
	while (*line && *line >= '0' && *line <= '9')
		line++;
	return (!*line);
}

int		is_valid_connexion(t_dlist *list, char *line)
{
	char	*tmp[2];

	if (!list)
		return (0);
	tmp[0] = line;
	while (*line)
	{
		while (*line && *line != '-')
			line++;
		if (*line == '-')
		{
			*line = '\0';
			if (find_room(list, tmp[0]) && find_room(list, line + 1))
				return (1);
			*line++ = '-';
		}
	}
	tmp[1] = line;
	return (0);
}
