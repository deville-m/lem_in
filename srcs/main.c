/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:13:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 21:05:24 by mdeville         ###   ########.fr       */
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
	size_t			i;
	t_dlist			*result;
	t_dlist			*list;
	t_room			*start;
	t_room			*end;
	t_room			**room;
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
	room = (t_room **)ft_dlst_to_tab(list);
	i = 0;
	ft_printf("length: %zu\n", ft_dlstlen(list));
	while (room[i])
	{
		ft_printf("%s ", room[i++]->name);
	}
	generate(ft_dlstlen(list), room);
	//result = solve(list, start, end);
	//generate(ft_dlstlen(start->neighbours), (t_room **)ft_dlst_to_tab(start->neighbours));
	// lem_in(result, nbant);
	ft_dlstdel(&list, free_room);
}
