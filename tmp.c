
	DIR				*homedir;
	struct dirent	*readhdir;
	struct stat		for_time;
	char			*tmp;

	if (!(homedir = opendir(".")))
		return ;



	DIR				*homedir;
	struct dirent	*readhdir;
	struct s_file	*filedata;
	struct stat		for_time;
	char			*tmp;
	

	if (!(homedir = opendir(".")))
		return 0;
	filedata.name = (char *)ft_memalloc(sizeof(char) * 256);
	file ((readhdir = readdir(homedir)))
	{
	//	tmp = (char *)ft_memalloc(sizeof(char) * 256);
		filedata->name = ft_strcpy(filedata->name, readhdir->d_name);
		printf("%s -----> ", filedata->name);
		fflush (stdout);
		lstat(filedata->name, &for_time);
		filedata->time = &for_time.st_mtime;
		printf("%s", ctime(filedata->time));
	//	stat(readhdir->d_name, (filedata->statbuf));
		printf("-------->%o\n", for_time.st_mode);
	}


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

void	sort_by_name(t_dir **item, t_dir **list)
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
		sort_by_name(item, list);
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
				sort_stuff(flags, &item, &current->subfiles);
				// kui filelist eksisteerib, siis hakka sinna sisse sortima uusi itemeid
		  		if (flags->flag_R && S_ISDIR(item->stat.st_mode) && ft_strcmp(item->bname, ".") && ft_strcmp(item->bname, ".."))
		  		{
		  			get_dir_data(flags, &current->subfiles);
		  		}
		  	}
		  	closedir (dir);
		} 
		else
		{
		  /* could not open directory */
		  	perror (current->name);
		  	return ;
		}
		current = current->next;
	}
}

////
----------------------------------------------------------------------------------------
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
