#include "ft_ls.h"

void	reverse_tdir_list(t_dir **arglist)
{
	t_dir	*prev;
	t_dir	*current;
	t_dir	*next;

	current = *arglist;
	next = current->next;
	current->next = NULL;
	while(next)
	{
		prev = current;
		current = next;
		next = current->next;
		current->next = prev;
		if (next->next == NULL)
		{
			next->next = current;
			*arglist = next;
			return ;
		}
	}
}

void	sort_by_time(t_dir **diritem, t_dir **arglist)
{
	t_dir	**link;
	t_dir	*current;

	link = arglist;
	current = *arglist;
	while (current)
	{
		if (is_modified_later((*diritem)->time, current->time))
		{
			*link = *diritem;
			(*diritem)->next = current;
			return ;
		}
		current = current->next;
		link = &(*link)->next;
	}
	*link = *diritem;
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

void	sort_filelist_into_arglist(t_flag *flags, t_file **filelist, t_dir **arglist)
{
	t_file	*current;
	t_dir	*diritem;

	current = *filelist;
	while (current)
	{
		diritem = tdirnew(current->name);
		insert_into_arglist(flags, &diritem, arglist);
		current = current->next;
	}
	if (flags->flag_r)
		reverse_tdir_list(arglist);
}
