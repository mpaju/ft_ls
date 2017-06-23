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
	DIR	*homedir;
	struct dirent	*readhdir;
	struct s_file			*filedata;
	struct stat		for_time;
	char	*tmp;

	if (!(filedata = (t_file *)ft_memalloc(sizeof(t_file))))
		return (0);
	if (!(filedata->filepath = (char *)malloc(sizeof(char) * 256)))
		return (0);
	if (!(filedata->time = (time_t *)malloc(sizeof(char) * 256)))
		return (0);
	if (!(filedata->name = (char *)ft_memalloc(sizeof(char) * 256)))
		return (0);
	if (!(homedir = opendir(find_args(ac, av))))
		return 0;
	//filedata.name = (char *)ft_memalloc(sizeof(char) * 256);
	while ((readhdir = readdir(homedir)))
	{
	//	tmp = (char *)ft_memalloc(sizeof(char) * 256);
		filedata->name = ft_strcpy(filedata->name, readhdir->d_name);
		printf("%s -----> ", filedata->name);
		fflush (stdout);
		stat(filedata->name, &for_time);
		filedata->time = &for_time.st_mtime;
		printf("%s", ctime(filedata->time));
	//	stat(readhdir->d_name, (filedata->statbuf));
	//	printf("buf->%o\n", filedata->statbuf->st_mode);

	}
	return (0);
}
