#include "ft_ls.h"
#include "libft/libft.h"
#include <stdio.h>

const char	*find_args(int ac, const char **av)
{
	return (av[1]);
}

int	init_structures(struct s_file *sfile)
{
	if (!(sfile = (struct s_file *)ft_memalloc(sizeof(struct s_file))))
			return (0);
	
	if (!(sfile->statbuf = (struct stat *)ft_memalloc(sizeof(struct stat))))
		return (0);
	return (1);
}

int main(int ac, const char **av)
{
	DIR	*homedir;
	struct dirent	*readhdir;
	struct s_file			*filedata;

	if (!(init_structures(filedata)))
		return (0);
	if (!(homedir = opendir(find_args(ac, av))))
		return 0;
	
	while ((readhdir = readdir(homedir)))
	{
		ft_strcpy(filedata->name, readhdir->d_name);
		printf("%s -----> ", filedata->name);
		stat(readhdir->d_name, (filedata->statbuf));
		printf("buf->%o\n", filedata->statbuf->st_mode);

	}
	return (0);
}
