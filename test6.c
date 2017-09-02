#include "ft_ls.h"

int main(int argc, char const *argv[])
{
	char		*file;
	struct stat	statinfo;
	int			total;
	file = ft_strdup((char*)argv[1]);
	if ((stat(file, &statinfo) == -1))
	{
		printf("invalid file\n");
		exit(1);
	}
	total = statinfo.st_blocks;
	printf("total: %d\n", total);
	return 0;
}
