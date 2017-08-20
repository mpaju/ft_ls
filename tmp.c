
	DIR				*homedir;
	struct dirent	*readhdir;
	struct stat		for_time;
	char			*tmp;

	if (!(homedir = opendir(".")))
		return ;



	

	if (!(homedir = opendir(".")))
		return 0;
	//filedata.name = (char *)ft_memalloc(sizeof(char) * 256);
	/*hile ((readhdir = readdir(homedir)))
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

	}*/
	DIR				*homedir;
	struct dirent	*readhdir;
	struct s_file	*filedata;
	struct stat		for_time;
	char			*tmp;