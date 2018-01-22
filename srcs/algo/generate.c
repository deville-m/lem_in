/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:58:24 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/22 18:28:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	generate(size_t n, t_dlist *list)
{
	size_t i;

	if (n == 1)
		ft_dlstiter(list, print_elem);
	else
	{
		i = 0;
		while (i < n - 1)
		{
			generate(n - 1, list);
			if (n % 2 == 0)
				ft_dlstswap(ft_dlstat(list, i), ft_dlstat(list, n - 1));
			else
				ft_dlstswap(ft_dlstat(list, 0), ft_dlstat(list, n - 1));
			i += 1;
		}
		generate(n - 1, list);
	}
}
