/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 22:32:10 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/23 21:15:54 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst);
		lst = lst->next;
	}
}
