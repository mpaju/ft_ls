#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_ls.h"

typedef struct s_stat{
	char *name;
	struct stat stat;
}		t_stat;

void	testapp(t_stat **tstat)
{
	struct stat statval;
	int		ret;

	ret = lstat("./link", &(*tstat)->stat);
}

int main(int argc, const char *argv[])
{
	t_stat	*tstat;
	struct stat statval;
	struct stat *teststat;
	char *time;

	tstat = (t_stat *)malloc(sizeof(tstat));
	testapp(&tstat);
	time = ctime(&(tstat)->stat.st_mtime);
	printf("%s\n", time);

	
	return 0;
}
