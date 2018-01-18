/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:37:33 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/19 00:55:21 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "lst.h"
#include "get_next_line.h"
#include "conversion.h"
#include "lem_in.h"
#include "ft_printf.h"

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
		ft_printf("ERROR\n");
		return (0);
	}
	free(tmp);
	return (1);
}

int		main(void)
{
	t_list			*list;
	t_room			*start;
	t_room			*end;
	unsigned int	nbant;

	if (!get_nbant(&nbant))
		return (1);
	start = NULL;
	end = NULL;
	list = parse(&start, &end);
	if (!list || !start || !end)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	ft_lstiter(list, print_room);
	ft_lstdel(&list, free_room);
}
