/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:37:33 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/18 19:37:55 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_string.h"
#include "lst.h"
#include "get_next_line.h"
#include "conversion.h"
#include "lem_in.h"
#include "ft_printf.h"

int	main(void)
{
	t_list			*list;
	t_room			*start;
	t_room			*end;
	unsigned int	nbant;
	char			*tmp;

	if (get_next_line(0, &tmp) != 1
		|| !ft_str_is_numeric(tmp)
		|| !(nbant = ft_atoi(tmp)))
	{
		free(tmp);
		ft_printf("ERROR\n");
		return (1);
	}
	free(tmp);
	start = NULL;
	end = NULL;
	list = parse(&start, &end);
	if (!list || !start || !end)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	print_graph(list);
	ft_lstdel(&list, free_room);
}
