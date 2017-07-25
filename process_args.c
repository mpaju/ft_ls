#include "ft_ls.h"

void		process_args(int ac, const char **av, t_flag *flags, t_list *arglist)
{
	int			i;
	struct stat	dirstat;
	time_t		time;
	t_dir		*newdir;

	i = 1;
	av++;
	while (*av[0] == '-' && i < ac)
	{
		process_flags(*av, flags);
		av++;
		i++;
		if (*av == '\0')
			break;
	}
	while (*av && i < ac)
	{
		first_sort(*av, arglist)
		av++;
		i++
	}
	//process_dirs
	if ((lstat(*av, &dirstat)) == -1)
		perror(*av);
		// ei tea kas tuleb oige error, ilmselt peaks olema mingi ls: " " jne
}
