#include "ft_ls.h"
#include <stdio.h>
int main(int argc, const char *argv[])
{
	DIR	*homedir;
	struct dirent	*readhdir;
	struct stat		statbuf;
	
	
	if (!(homedir = opendir("../")))
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
