/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:13:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/24 22:06:43 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 19225520f9d3f1258bd478241aad52f213d29412
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
		ft_printf("%s\n", tmp);
		free(tmp);
	}
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
	t_dlist			*path;
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
		ft_fprintf(2, "ERROR\n");
		return (1);
	}
	//ft_dlstiter(list, print_room);
	prepare(list, start, end);
	path = NULL;
	result = path_finding(list, find_room(list, "1"), end);
	ft_dlstprepend(&path, ft_dlstlink(result, sizeof(t_dlist)));
	// result = solve(list, start, end, nbant);
	ft_printf("result = %p\n", result);
	// ft_dlstiter(result, print_room);
	ft_dlstiter(path, print_path);
	// lem_in(result, nbant);
	// ft_dlstdel(&list, free_room);
}
