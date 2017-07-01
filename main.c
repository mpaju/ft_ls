#include "ft_ls.h"
#include "libft/libft.h"
#include <stdio.h>

int	init_structures(struct s_file *sfile)
{
	//if (!(sfile = ft_lstnew(sfile, sizeof(t_file))))
	//	return (0);
	
	if (!(sfile = (t_file *)malloc(sizeof(t_file))))
			return (0);
	
	if (!(sfile->filepath = (char *)malloc(sizeof(char) * 256)))
		return (0);
	if (!(sfile->time = (time_t *)malloc(sizeof(char) * 256)))
		return (0);
	if (!(sfile->name = (char *)ft_memalloc(sizeof(char) * 256)))
		return (0);
	return (1);
}

int main(int ac, const char **av)
{
	DIR				*homedir;
	struct dirent	*readhdir;
	struct s_file	*filedata;
	struct stat		for_time;
	char			*tmp;
	t_flag			flags;
	t_dir			paths;

	get_args(ac, av, &flags, &paths);
	ft_ls(&paths, &flags);
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
	return (0);
}
