/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:45:48 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/17 15:21:21 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"

t_dlist	*ft_dlstcpy(t_dlist *head)
{
	t_dlist *res;

	res = NULL;
	if (!head)
		return (NULL);
	while (head)
	{
		ft_dlstprepend(&res, ft_dlstnew(head->content, head->content_size));
		head = head->next;
	}
	return (res);
}
