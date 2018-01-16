/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:37:33 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/16 17:14:41 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem_in.h"

int main()
{
	t_roomlist	*list;
	t_roomlist	*start;
	t_roomlist	*end;

	start = NULL;
	end = NULL;
	list = parse_room(&start, &end);
	if (!list)
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	parse_connexion(list, start, end);
	if (!connected(start, end))
	{
		write(1, "ERROR\n", 6);
		return (2);
	}
	lem_in(list, start, end);
}
