#include "ft_ls.h"

void	wrong_flag(const char *av)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd((char)*av, 2);
	ft_putstr_fd("\nusage: ls [-alrRt] [file ...]\n", 2);
	exit(1);

}

void	check_empty_arg(int ac, const char **av)
{
	while (ac > 1)
	{
		// peab testima nii, et viimane argument oleks ""
		if (*av == '\0')
		{
			ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
			exit (1);
		}
		ac--;
		av++;
	}
}
