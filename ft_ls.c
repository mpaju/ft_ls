/* ************************************************************************** */
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
	while ((name[size]) != '/' && size != -1)
		size--;
	if (size == -1)
		return (ft_strjoin(name, "/"));
	return (ft_strncpy(ft_strnew(size + 2), name, size + 1));
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
		sort_by_name(item, list);
}
/*
void	get_info
{
	DIR 			*dir;
	struct dirent	*open_dir;

	if ((dir = opendir (current->name)) != NULL) 
		{
			while ((open_dir = readdir (dir)) != NULL) 
			{
				item = tdirnew(ft_strjoin(current->name, ft_strjoin("/", open_dir->d_name)));
		  	}
		  	closedir (dir);
		} 
		else
		{
		  	perror (current->name);
		  	return ;
		}
}
*/	

t_dir	*free_tdir_and_return_next(t_dir *item)
{
	t_dir	*next;

	if (*item)
	{
		next = item->next;
		free(item->name);
		free(item->bname);
		free(item->path);
	}
	return (next);
	// char			*name;
	// char			*bname;
	// char			*path;
	// int 			error_nr;	
	// time_t			time;
	// struct stat		stat;
	// struct s_dir	*subfiles;
	// struct s_dir	*next;
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
	DIR 			*dir;
	struct dirent	*open_dir;
	t_dir			*item;
	t_dir			*current;

	if ((dir = opendir ((*arg)->name)) != NULL) 
	{
	  /* print all the files and directories within directory */
		while ((open_dir = readdir (dir)) != NULL) 
		{
			// vbla polnud koige parem mote tdirnew-d muuta
			if ((!flags->flag_a && ft_strncmp(open_dir->d_name, ".", 1)) || flags->flag_a)
			{
				item = tdirnew(ft_strjoin((*arg)->name, ft_strjoin("/", open_dir->d_name)));
				sort_stuff(flags, &item, &(*arg)->subfiles);
			}
			// kui filelist eksisteerib, siis hakka sinna sisse sortima uusi itemeid
	  	}
	  	closedir (dir);
	  	if (flags->flag_r && (*arg)->subfiles)
	  		reverse_tdir_list(&(*arg)->subfiles);
	} 
	else
	{
	  /* could not open directory */
	  	perror ((*arg)->name);
	  	return ;
	}
	current = (*arg)->subfiles;
	while (current)
	{
		if (flags->flag_R && S_ISDIR(current->stat.st_mode) && ft_strcmp(current->bname, ".") && ft_strcmp(current->bname, ".."))
	  	{
	  		//print_smth(flags, &current);
	  		smth(flags, &current);
	  	}
	  	// should free current here
		current = current->next;
	}
}
void	get_dir_data(t_flag *flags, t_dir **arglist)
{
	t_dir			*current;
	t_dir			*item;

	current = *arglist;
	while (current)
	{
		//printf("%s\n", current->bname);
		smth(flags, &current);	
		current = current->next;
	}
}



void	ft_ls(t_flag *flags, t_file **filelist)
{
	t_dir	*arglist;

	arglist = NULL;
	sort_filelist_into_arglist(flags, filelist, &arglist);
	print_and_remove_normal_files(flags, &arglist);
	if (!arglist)
		exit(1);
	get_dir_data(flags, &arglist);
	flags->single_dir ? print_single_dir(flags, &arglist) : print_arglist(flags, &arglist);
	ft_putchar('\b');
	return ;
}
