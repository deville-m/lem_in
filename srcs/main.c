/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:13:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 21:49:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

static int	get_nbant(unsigned int *nbant)
{
	char	*tmp;

	tmp = NULL;
	while (get_next_line(0, &tmp) == 1 && is_comment(tmp))
		free(tmp);
	if (!tmp
		|| !ft_str_is_numeric(tmp)
		|| !(*nbant = ft_atoi(tmp)))
	{
		free(tmp);
		ft_fprintf(2, "ERROR\n");
		return (0);
	}
	ft_printf("%d\n", *nbant);
	free(tmp);
	return (1);
}

int			main(void)
{
	t_list			*result;
	t_list			*list;
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
		ft_fprintf(2, "ERROR\n");
		return (1);
	}
	ft_printf("Start: %s / end: %s\n", start->name, end->name);
	disconnect(find_room(list, "3"), find_room(list, "4"));
	ft_lstiter(list, print_room);
//	result = solve(list, start, end);
//	ft_lstiter(result, print_path);
	// lem_in(result, nbant);
	ft_lstdel(&list, free_room);
}
