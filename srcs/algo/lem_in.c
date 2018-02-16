/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:25:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/16 17:21:32 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	addstartend(t_dlist *result, t_room *start, t_room *end)
{
	t_dlist	*add;
	t_dlist	*tmp;

	tmp = result;
	while (tmp)
	{
		add = LIST(tmp);
		if (!ROOM(add))
			ft_dlstpop(&add);
		ft_dlstappend(&add, ft_dlstlink(end, sizeof(*end)));
	 	tmp->content = add;
		tmp = tmp->next;
	}
	tmp = result;
	while (tmp)
	{
		add = LIST(tmp);
		ft_dlstprepend(&add, ft_dlstlink(start, sizeof(*end)));
		tmp->content = add;
		tmp = tmp->next;
	}
}

void	setupgrp(t_dlist *result, t_dlist *antloc[], unsigned nbant)
{
	t_dlist	*tmp;
	size_t	maxlen;
	size_t	i;
	size_t	j;

	ft_printf("nbant = %u | maxlen = %u\n", nbant, maxlen = ft_dlstlen(get_max(result)) - 2);
	j = 0;
	tmp = result;
	antloc[j] = NULL;
	while (nbant && tmp)
	{
		i = 0;
		while (nbant && i < maxlen - (ft_dlstlen(LIST(tmp)) - 2))
		{
			ft_dlstprepend(&antloc[j + i++], ft_dlstlink(LIST(tmp), sizeof(*tmp)));
			antloc[j + i] = NULL;
			nbant--;
		}
		j += i;
		tmp = tmp->next;
	}
	tmp = result;
	while (nbant)
	{
		if (!tmp)
			tmp = result;
		ft_dlstprepend(&antloc[j++], ft_dlstlink(LIST(tmp), sizeof(*tmp)));
		antloc[j] = NULL;
		tmp = tmp->next;
		nbant--;
	}
}

void	clean_it(t_dlist *elem)
{
	ROOM(elem)->in = 0;
}

void	apply(t_dlist *result, t_dlist *antloc[], t_room *end)
{
	t_dlist	*tmp;
	size_t	j;
	size_t	i;
	char	chg;

	i = 0;
	while (antloc[i])
	{
		chg = 0;
		j = i;
		while (antloc[j])
		{
			if (LIST(antloc[j])
				&& ROOM(LIST(antloc[j])) != end
				&& ROOM(LIST(antloc[j])->next)->in == 0)
			{
				// ft_printf("before = %s ", ROOM(LIST(antloc[j]))->name);
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
		tmp = result;
		while (tmp)
		{
			ft_dlstiter(LIST(tmp), clean_it);
			tmp = tmp->next;
		}
		if (ROOM(LIST(antloc[i])) == end)
			i++;
	}
}

void	antlocdel(t_dlist *antloc[])
{
	size_t	i;

	i = 0;
	while (antloc[i])
	{
		ft_dlstdel(&antloc[i], NULL);
		i++;
	}
}

void	lem_in(t_dlist *result, unsigned int nbant, t_room *start, t_room *end)
{
	t_dlist	*antloc[nbant + 1];

	addstartend(result, start, end);
	ft_printf("LEN = %u | PATH : \n", ft_dlstlen(LIST(result)));
	ft_dlstiter(result, print_path);
	setupgrp(result, antloc, nbant);
	apply(result, antloc, end);
}
