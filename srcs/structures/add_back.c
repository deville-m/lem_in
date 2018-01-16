/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:37:11 by mdeville          #+#    #+#             */
/*   Updated: 2018/01/16 19:31:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_back(t_roomlist **head, t_roomlist *elem)
{
	if (!head || !elem)
		return ;
	add_elem(head, elem);
	rotate(head);
}
