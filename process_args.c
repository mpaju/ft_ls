#include "ft_ls.h"

void		process_args(int ac, const char **av, t_flag *flags, t_file **filelist)
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
	if (ac - i == 1)
		flags->single_dir = 1;
	while (*av && i < ac)
	{
		first_sort(*av, filelist);
		av++;
		i++;
	}
}