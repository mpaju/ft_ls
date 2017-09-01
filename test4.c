#include "ft_ls.h"

int main(int argc, char const *argv[])
{
	int	*buf;
	ssize_t	ret;
	buf = (int *)ft_memalloc(sizeof(int) * 5);
	ret = getxattr("./", "errors.c", (void *)buf, 5);
	printf("%zd, %d\n", ret, *buf);
	return 0;
}