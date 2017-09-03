/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:46:22 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 17:40:36 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	insert_last_pos(t_dir **diritem, t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	while (current->next)
		current = current->next;
	current->next = *diritem;
}

void	reverse_tdir_list(t_dir **arglist)
{
	t_dir	*prev;
	t_dir	*current;
	t_dir	*next;

	current = *arglist;
	next = current->next;
	current->next = NULL;
	while (next)
	{
		if (next->next == NULL)
		{
			next->next = current;
			*arglist = next;
			return ;
		}
		prev = current;
		current = next;
		next = current->next;
		current->next = prev;
	}
}

void	sort_stuff(t_flag *flags, t_dir **item, t_dir **list)
{
	if (!(*list))
	{
		*list = *item;
		return ;
	}
	if (flags->flag_us)
		sort_by_size(item, list);
	else if (flags->flag_t)
		sort_by_time(item, list);
	else
		sort_by_name(item, list);
}

void	insert_into_arglist(t_flag *flags, t_dir **diritem, t_dir **arglist)
{
	if (!(*arglist))
	{
		*arglist = *diritem;
		return ;
	}
	if (flags->flag_t)
		sort_by_time(diritem, arglist);
	else
		insert_last_pos(diritem, arglist);
}

void	sort_filelist_into_arglist(t_flag *flags, t_file **filelist, \
	t_dir **arglist)
{
	t_file	*current;
	t_dir	*diritem;

	current = *filelist;
	while (current)
	{
		diritem = tdirnew(flags, current->name);
		insert_into_arglist(flags, &diritem, arglist);
		current = current->next;
	}
	if (flags->flag_r)
		reverse_tdir_list(arglist);
}
