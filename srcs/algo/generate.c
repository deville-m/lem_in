/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:58:24 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/18 15:19:48 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void		print_tab(t_room **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		ft_printf("%s ", tab[i++]->name);
	ft_printf("\n");
}

static	void		swap(t_room **e1, t_room **e2)
{
	t_room	*tmp;

	tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

void				generate(size_t n, t_room *tab[])
{
	size_t	i;

	if (n == 1)
		print_tab(tab);
	else
	{
		i = 0;
		while (i < n - 1)
		{
			generate(n - 1, tab);
			if (n % 2 == 0)
				swap(&tab[i], &tab[n - 1]);
			else
				swap(&tab[0], &tab[n - 1]);
			i += 1;
		}
		generate(n - 1, tab);
	}
}
