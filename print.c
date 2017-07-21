#include "ft_ls.h"

void	print_type(mode_t mode)
{
	S_ISREG(mode) ? ft_putchar('-') : 0;
	S_ISDIR(mode) ? ft_putchar('d') : 0;
	S_ISLNK(mode) ? ft_putchar('l') : 0;
	S_ISBLK(mode) ? ft_putchar('b') : 0;
	S_ISCHR(mode) ? ft_putchar('c') : 0;
	S_ISFIFO(mode) ? ft_putchar('p') : 0;
	S_ISSOCK(mode) ? ft_putchar('s') : 0;
}