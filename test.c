#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_ls.h"

void print_type(mode_t mode);

int main(int argc, const char *argv[])
{
	struct stat teststat;
	char *time;

	lstat("./athr", &teststat);
	print_type(teststat.st_mode);
	time = ctime(&teststat.st_mtime);
	printf("%s\n", time);
	return 0;
}
