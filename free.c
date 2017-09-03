/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:28:21 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 16:44:21 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*free_tdir_and_return_next(t_dir *item)
{
	t_dir	*nextitem;

	nextitem = NULL;
	if (item)
	{
		nextitem = item->next;
		if (item->name)
		{
			free(item->name);
			item->name = NULL;
		}
		if (item->path)
		{
			free(item->path);
			item->path = NULL;
		}
		if (item->bname)
		{
			free(item->bname);
			item->bname = NULL;
		}
		free(item);
	}
	return (nextitem);
}
