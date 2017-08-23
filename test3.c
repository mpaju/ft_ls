#include "ft_ls.h"

int main(int argc, char const *argv[])
{
	t_dir	*tdir;
	t_dir	*tmp;

	tdir = (t_dir *)malloc(sizeof(tdir));
	tdir->name = "./link";
	lstat(tdir->name, &tdir->stat);
	tmp = tdir;
	free(tdir);
	tdir = NULL;
	return 0;
}