/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:39:01 by mdeville          #+#    #+#             */
/*   Updated: 2018/02/18 15:42:03 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlst.h"
#include "ft_string.h"
#include "ft_printf.h"

void	log_print(t_dlist *elem)
{
	ft_printf("%s\n", (char *)elem->content);
}

void	free_str(void *str, size_t size)
{
	(void)size;
	free(str);
}

int		logger(char *line, int mode)
{
	static t_dlist *logger = NULL;

	if (mode && logger)
	{
		ft_dlstreverse(&logger);
		ft_dlstiter(logger, log_print);
	}
	else if (line)
		ft_dlstprepend(&logger,
				ft_dlstlink(ft_strdup(line), ft_strlen(line) + 1));
	if (!line)
		ft_dlstdel(&logger, free_str);
	return (1);
}
