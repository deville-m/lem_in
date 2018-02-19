/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:21:20 by vlay              #+#    #+#             */
/*   Updated: 2018/02/19 23:49:00 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_tabcpy(char **tab, size_t hauteur)
{
	char	**cpy;
	size_t	j;

	j = 0;
	cpy = (char **)malloc(sizeof(char *) * (hauteur + 1));
	while (tab[j])
	{
		cpy[j] = ft_strdup(tab[j]);
		j++;
	}
	cpy[j] = NULL;
	return (cpy);
}

size_t	ft_tabheight(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	ft_tabdel(char **tab)
{
	size_t	j;

	j = 0;
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}
