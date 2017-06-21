#include "ft_ls.h"
#include <stdio.h>

const char	*find_args(int ac, const char **av)
{
	return (av[1]);
}


int main(int ac, const char **av)
{
	DIR	*homedir;
	struct dirent	*readhdir;
	struct stat		statbuf;
	
	
	if (!(homedir = opendir(find_args(ac, av))))
		return 0;
	while ((readhdir = readdir(homedir)))
	{
		printf("%s -----> ", readhdir->d_name);
		stat(readhdir->d_name, &statbuf);
		printf("buf->%o\n", statbuf.st_mode);

	}
	stat("asdkjsakj", &statbuf);
	printf("buf->%o\n", statbuf.st_mode);

	return (0);
}
