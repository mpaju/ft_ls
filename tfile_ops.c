/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfile_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:45:58 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 14:46:50 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*tfilenew(char *name)
{
	t_file	*ret;

	ret = (t_file *)ft_memalloc(sizeof(ret));
	if (name)
		ret->name = ft_strdup(name);
	return (ret);
}

void	tfile_add_first(t_file *newitem, t_file **filelist)
{
	newitem->next = *filelist;
	*filelist = newitem;
}

void	tfile_add_after(t_file *newitem, t_file *filelist)
{
	newitem->next = filelist->next;
	filelist->next = newitem;
}

void	tfile_add_last(t_file *newitem, t_file *filelist)
{
	while (filelist->next != NULL)
	{
		filelist = filelist->next;
	}
	filelist->next = newitem;
	newitem->next = NULL;
}
