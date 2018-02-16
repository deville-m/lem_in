/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:13:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/16 18:10:21 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

static int	get_nbant(unsigned int *nbant)
{
	char	*tmp;

	tmp = NULL;
	while (get_next_line(0, &tmp) == 1 && is_comment(tmp))
	{
		logger(tmp, 0);
		free(tmp);
	}
	if (!tmp
		|| !ft_str_is_numeric(tmp)
		|| !(*nbant = ft_atou(tmp)))
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
		logger(NULL, 1);
		ft_fprintf(2, "ERROR\n");
		return (1);
	}
	logger(NULL, 1);
	ft_dlstiter(list, clean_it);
	result = solve(list, start, end, nbant);
	ft_dlstiter(list, print_room);
	ft_dlstiter(result, print_path);
	lem_in(result, nbant, start, end);
	ft_dlstdel(&list, free_room);
}
