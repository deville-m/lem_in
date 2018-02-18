/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:25:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/18 17:55:11 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void			addstartend(t_dlist *result, t_room *start, t_room *end)
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

static	inline	void	set_secondphase(t_dlist *result,
						unsigned nbant, size_t j, t_dlist *antloc[])
{
	t_dlist	*tmp;

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

void					setupgrp(t_dlist *result,
						t_dlist *antloc[], unsigned nbant)
{
	t_dlist	*tmp;
	size_t	maxlen;
	size_t	i;
	size_t	j;

	maxlen = ft_dlstlen(get_max(result)) - 2;
	j = 0;
	tmp = result;
	antloc[j] = NULL;
	while (nbant && tmp)
	{
		i = 0;
		while (nbant && i < maxlen - (ft_dlstlen(LIST(tmp)) - 2))
		{
			ft_dlstprepend(&antloc[j + i++],
					ft_dlstlink(LIST(tmp), sizeof(*tmp)));
			antloc[j + i] = NULL;
			nbant--;
		}
		j += i;
		tmp = tmp->next;
	}
	set_secondphase(result, nbant, j, antloc);
}

void					antlocdel(t_dlist *antloc[])
{
	size_t	i;

	i = 0;
	while (antloc[i])
	{
		ft_dlstdel(&antloc[i], NULL);
		i++;
	}
}

void					lem_in(t_dlist *result, unsigned int nbant,
						t_room *start, t_room *end)
{
	t_dlist	**antloc;

	if (!(antloc = (t_dlist **)malloc(sizeof(t_dlist *) * (nbant + 1))))
		return ;
	addstartend(result, start, end);
	setupgrp(result, antloc, nbant);
	apply(antloc, end);
	antlocdel(antloc);
	free(antloc);
}
