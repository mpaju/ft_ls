#include "ft_ls.h"

void	sort_by_time(t_dir **diritem, t_dir **arglist)
{
	t_dir	**link;
	t_dir	*current;

	link = arglist;
	current = *arglist;
	while (current)
	{
		if (has_lower_int_value(current->))
	}
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
	struct stat	statinfo;


	current = *filelist;
	while (current)
	{
		lstat(current->name, &statinfo);
		diritem = tdirnew(current->name, statinfo.st_mtime);
		insert_into_arglist(flags, diritem, arglist);
	}
}