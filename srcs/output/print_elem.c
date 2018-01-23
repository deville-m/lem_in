/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:08:19 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/23 21:03:26 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_elem(t_dlist *elem)
{
	if (!elem || !elem->content)
		return ;
	if (elem->next)
		ft_printf("%s - ", ROOM(elem)->name);
	else
		ft_printf("%s\n", ROOM(elem)->name);
}
