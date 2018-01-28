/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:25:00 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/28 21:45:10 by vlay             ###   ########.fr       */
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

void	initgrp(int group[], t_dlist *result, unsigned nbant)
{
	t_dlist	*tmp;
	size_t	i;
	size_t	maxlen;
	size_t	grp;

	i = 0;
	tmp = result;
	maxlen = ft_dlstlen(get_max(result));
	while (tmp)
	{
		group[i++] = maxlen - ft_dlstlen(LIST(tmp));
		nbant -= maxlen - ft_dlstlen(LIST(tmp));
		tmp = tmp->next;
	}
	group[i] = -1;
	i = 0;
	tmp = result;
	grp = nbant / ft_dlstlen(result);
	while (tmp)
	{
		group[i++] += grp;
		tmp = tmp->next;
	}
	grp = nbant % ft_dlstlen(result);
	tmp = result;
	i = 0;
	while (tmp)
	{
		if (grp)
		{
			group[i]++;
			grp--;
		}
		i++;
		tmp = tmp->next;
	}
}

void	print_grp(int group[])
{
	while (*group >= 0)
	{
		ft_printf("group = %d\n", *group);
		group++;
	}
}

void	setupgrp(t_dlist *result, t_dlist *antloc[], int group[], unsigned nbant)
{
	t_dlist	*tmp;
	unsigned	i;
	unsigned	g;

	i = 0;
	tmp = NULL;
	g = 0;
	while (nbant)
	{
		if (group[g] == -1)
			g = 0;
		if (!tmp)
			tmp = result;
		antloc[i] = NULL;
		ft_dlstprepend(&antloc[i++], ft_dlstlink(LIST(tmp), sizeof(*tmp)));
		tmp = tmp->next;
		if (group[g] > 0)
		{
			nbant--;
			group[g] -= 1;
		}
		g++;
	}
	antloc[i] = NULL;
}

void	clean_it(t_dlist *elem)
{
	ROOM(elem)->in = 0;
}

void	apply(t_dlist *list, t_dlist *antloc[], t_room *end)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (antloc[i])
	{
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
			}
			j++;
		}
		ft_printf("\n");
		ft_dlstiter(list, clean_it);
		if (ROOM(LIST(antloc[i])) == end)
			i++;
	}
}

void	lem_in(t_dlist *list, t_dlist *result, unsigned int nbant, t_room *start, t_room *end)
{
	int		group[ft_dlstlen(result) + 1];
	t_dlist	*antloc[nbant + 1];

	initgrp(group, result, nbant);
	print_grp(group);
	addstartend(result, start, end);
	setupgrp(result, antloc, group, nbant);
	ft_dlstiter(list, clean_it);
	apply(list, antloc, end);
}
