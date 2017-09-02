#include "ft_ls.h"

int main(int argc, char const *argv[])
{
	char		*file;
	struct stat	statinfo;
	struct passwd *pwinfo;
	
	file = ft_strdup((char*)argv[1]);
	if ((stat(file, &statinfo) == -1))
	{
		printf("invalid file\n");
		exit(1);
	}
	pwinfo = getpwuid(statinfo.st_uid);
	return 0;
}
