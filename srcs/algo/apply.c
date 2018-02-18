/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:26:22 by vlay              #+#    #+#             */
/*   Updated: 2018/02/18 15:26:32 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	inline	void	move(t_dlist *antloc[], t_room *end, size_t j)
{
	char	chg;

	chg = 0;
	while (antloc[j])
	{
		if (LIST(antloc[j])
			&& ROOM(LIST(antloc[j])) != end
			&& ROOM(LIST(antloc[j])->next)->in == 0)
		{
			ROOM(LIST(antloc[j]))->in = 0;
			antloc[j]->content = LIST(antloc[j])->next;
			ft_printf("L%u-%s ", j + 1, ROOM(LIST(antloc[j]))->name);
			if (ROOM(LIST(antloc[j])) != end)
				ROOM(LIST(antloc[j]))->in = 1;
			chg++;
		}
		j++;
	}
	if (chg)
		ft_printf("\n");
}

void					apply(t_dlist *antloc[], t_room *end)
{
	size_t	i;

	i = 0;
	while (antloc[i])
	{
		move(antloc, end, i);
		if (ROOM(LIST(antloc[i])) == end)
			i++;
	}
}
