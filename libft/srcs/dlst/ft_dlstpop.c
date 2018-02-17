/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:27:57 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/17 15:32:19 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlst.h"
#include <stdlib.h>

t_dlist	*ft_dlstpop(t_dlist **alst)
{
	void	*content;
	t_dlist	*res;

	if (!alst || !*alst)
		return (NULL);
	res = *alst;
	*alst = (*alst)->next;
	content = res->content;
	free(res);
	return (content);
}
