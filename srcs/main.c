/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:13:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/17 18:33:05 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include <limits.h>

static int	get_nbant(unsigned int *nbant)
{
	char	*tmp;
	int		ret;

	tmp = NULL;
	while ((ret = get_next_line(0, &tmp)) == 1 && is_comment(tmp))
	{
		logger(tmp, 0);
		free(tmp);
	}
	if (ret <= 0
		|| !tmp
		|| !ft_str_is_numeric(tmp)
		|| !(*nbant = ft_atou(tmp))
		|| *nbant > INT_MAX)
	{
		free(tmp);
		logger(NULL, 0);
		ft_fprintf(2, "ERROR\n");
		return (0);
	}
	logger(tmp, 0);
	free(tmp);
	return (1);
}

void		free_path(void *elem, size_t size)
{
	t_dlist	*next;
	t_dlist	*list;

	if (!elem)
		return ;
	list = (t_dlist *)elem;
	(void)size;
	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
	elem = NULL;
}

int			main(void)
{
	t_dlist			*result;
	t_dlist			*list;
	t_room			*start;
	t_room			*end;
	unsigned int	nbant;

	if (!get_nbant(&nbant))
		return (1);
	start = NULL;
	end = NULL;
	list = parse(&start, &end);
	if (!list || !start || !end || !is_connected(start, end))
	{
		ft_dlstdel(&list, free_room);
		logger(NULL, 0);
		ft_fprintf(2, "ERROR\n");
		return (1);
	}
	logger(NULL, 1);
	result = solve(list, start, end, nbant);
	lem_in(result, nbant, start, end);
	ft_dlstdel(&result, free_path);
	ft_dlstdel(&list, free_room);
}
