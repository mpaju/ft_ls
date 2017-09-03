#include "ft_ls.h"

void	sort_stuff(t_flag *flags, t_dir **item, t_dir **list)
{
	if (!(*list))
	{
		*list = *item;
		return ;
	}
	if (flags->flag_t)
		sort_by_time(item, list);
	else
		sort_by_name(item, list);
}

void	print_smth(t_flag *flags, t_dir **item)
{
	t_dir	*current;

	printf("%s:\n", (*item)->name);
	current = (*item)->subfiles;
	while (current)
	{
		printf("%s\n", current->bname);
		current = current->next;
	}
}

void	smth(t_flag *flags, t_dir **arg)
{
	DIR				*dir;
	struct dirent	*open_dir;
	t_dir			*item;
	t_dir			*current;

	if ((dir = opendir((*arg)->name)) != NULL)
	{
		while ((open_dir = readdir(dir)) != NULL)
		{
			if ((!flags->flag_a && ft_strncmp(open_dir->d_name, ".", 1)) || flags->flag_a)
			{
				item = tdirnew(flags, get_filename((*arg)->name, open_dir->d_name));
				sort_stuff(flags, &item, &(*arg)->subfiles);
			}
		}
		closedir(dir);
		if (flags->flag_r && (*arg)->subfiles)
			reverse_tdir_list(&(*arg)->subfiles);
	}
	else
	{
		perror((*arg)->name);
		return ;
	}
	flags->single_dir ? print_single_dir(flags, arg) : print_arglist(flags, arg);
	current = (*arg)->subfiles;
	while (current)
	{
		if (flags->flag_ur && S_ISDIR(current->stat.st_mode) && ft_strcmp(current->bname, ".") && ft_strcmp(current->bname, ".."))
		{
			smth(flags, &current);
		}
		current = free_tdir_and_return_next(current);
	}
}

void	get_dir_data(t_flag *flags, t_dir **arglist)
{
	t_dir			*current;
	t_dir			*item;

	current = *arglist;
	while (current)
	{
		smth(flags, &current);
		current = free_tdir_and_return_next(current);
	}
	exit(1);
}

void	ft_ls(t_flag *flags, t_file **filelist)
{
	t_dir	*arglist;

	arglist = NULL;
	if (!*filelist)
		exit (0);
	sort_filelist_into_arglist(flags, filelist, &arglist);
	print_and_remove_normal_files(flags, &arglist);
	if (!arglist)
		exit(1);
	get_dir_data(flags, &arglist);
	return ;
}
