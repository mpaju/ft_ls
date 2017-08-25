#include "ft_ls.h"

/*
void	sorting(diritem, dirlist)
{
	if (flags->flag_t)
		sort_by_time(...);
	else
		sort_by_alpha(...);
}

void	give_tdir(flags, arglist)
{
	while (dir)
	{
		// init diritem
		diritem = dir?;
		diritem = tdirnew(dir);
		// sort diritem to right sub
		lstat(diritem->name, &(*diritem)->stat);
		sorting(arglist, diritem);
		if (S_ISDIR(diritem->name))
			sorting(flags, &arglist->subdir, diritem);
	}
}
*/
char	*get_pathname(char *name)
{
	int	size;

	size = ft_strlen(name);
	size--;
	while ((name[size]) != '/')
		size--;
	if (size == -1)
		return (ft_strjoin(name, "/"));
	return (ft_strncpy(ft_strnew(size + 2), name, size + 1));
}

void	sort_by_alpha(t_dir **item, t_dir **list)
{
	t_dir	*current;
	t_dir	**link;

	current = *list;
	link = list;
	while (current)
	{
		if ((has_lower_alpha_value((*item)->bname, current->bname)))
		{
			*link = *item;
			(*item)->next = current;
			return ;
		}
		current = current->next;
		link = &(*link)->next;
	}
	*link = *item;
}

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
		sort_by_alpha(item, list);
}

void	get_dir_data(t_flag *flags, t_dir **arglist)
{
	DIR 			*dir;
	struct dirent	*open_dir;
	t_dir			*current;
	t_dir			*item;

	current = *arglist;
	while (current)
	{
		if ((dir = opendir (current->name)) != NULL) 
		{
		  /* print all the files and directories within directory */
			while ((open_dir = readdir (dir)) != NULL) 
			{
				// vbla polnud koige parem mote tdirnew-d muuta
				item = tdirnew(ft_strjoin(current->name, ft_strjoin("/", open_dir->d_name)));
				sort_stuff(flags, &item, &current->filelist);
				// kui filelist eksisteerib, siis hakka sinna sisse sortima uusi itemeid
		  		if (flags->flag_R && S_ISDIR(item->stat.st_mode))
		  		{
		  			sort_stuff(flags, &item, &current->subdir);
		  			get_dir_data(flags, &current->subdir);
		  		}
		  	}
		  	closedir (dir);
		} 
		else
		{
		  /* could not open directory */
		  	perror ("");
		  	return ;
		}
		current = current->next;
	}
}

void	ft_ls(t_flag *flags, t_file **filelist)
{
	t_dir	*arglist;

	sort_filelist_into_arglist(flags, filelist, &arglist);
	print_and_remove_normal_files(flags, &arglist);
	get_dir_data(flags, &arglist);
	print_tdir_items(&arglist);
	
	return ;
}
