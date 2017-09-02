#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_ls.h"

int main(int argc, const char *argv[])
{
	struct stat statval;
	char *time;

	lstat(ft_strdup((char*)argv[1]), &statval);
	time = ctime(&statval.st_mtime);
	printf("%sasd\n", time);

	
	return 0;
}
