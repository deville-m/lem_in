/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:33:13 by vlay              #+#    #+#             */
/*   Updated: 2018/02/18 15:44:58 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

static	inline	size_t	mapcomplete(t_dlist *list, t_room *begin, t_room *goal)
{
	size_t	len;
	size_t	i;
	t_dlist	*tmp;

	tmp = list;
	i = 0;
	len = ft_dlstlen(list);
	while (tmp)
	{
		if (ROOM(tmp)->occupied >= len)
			return (1);
		if (ROOM(tmp) != begin && ROOM(tmp) != goal && ROOM(tmp)->occupied > 1)
			i++;
		tmp = tmp->next;
	}
	return ((i >= len - 2) ? 1 : 0);
}

static	inline	void	group_it(t_dlist *try, t_dlist **best, unsigned nbant)
{
	t_dlist	*group;

	group = NULL;
	if (score_it((group = group_up(try)), nbant) < score_it(*best, nbant))
	{
		ft_dlstdel(best, free_path);
		*best = ft_dlstdup(group);
	}
	ft_dlstdel(&group, NULL);
}

static	void			path_found(size_t *pick, t_dlist **try, t_dlist *path)
{
	if (!alreadyfound(*try, path))
	{
		ft_dlstprepend(try, ft_dlstlink(path, sizeof(**try)));
		*pick = 0;
	}
	else
	{
		*pick = *pick + 1;
		free_path(path, sizeof(*path));
	}
}

t_dlist					*get_path(t_dlist *list,
						t_room *begin, t_room *goal, unsigned nbant)
{
	t_dlist	*path;
	t_dlist	*try;
	t_dlist	*best;
	size_t	pick;
	size_t	maxpath;

	best = NULL;
	try = NULL;
	pick = 0;
	maxpath = (ft_dlstlen(begin->neighbours) > nbant)
		? nbant : ft_dlstlen(begin->neighbours);
	while (!best || (ft_dlstlen(best) < maxpath
		&& !mapcomplete(list, begin, goal)))
	{
		if ((path = path_finding(list, begin, goal)))
			path_found(&pick, &try, path);
		if (pick > ft_dlstlen(begin->neighbours))
			break ;
		group_it(try, &best, nbant);
	}
	ft_dlstdel(&try, free_path);
	return (best);
}
