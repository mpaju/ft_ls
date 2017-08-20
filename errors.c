#include "ft_ls.h"

void	wrong_flag(const char *av)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd((char)av, 2);
	ft_putstr_fd("\nusage: ls [-alrRt] [file ...]\n", 2);
	exit(1);

}

void	find_first_valid(t_flag *flags, t_file **filelist)
{
	struct stat	dirstat;
	t_file	*current;
	t_file	*tmp;

	current = *filelist;
	while ((lstat(current->name, &dirstat)) == -1)
	{
		printf("not valid: %s\n", current->name);
		*filelist = current->next;
		tmp = current;
		current = current->next;
		free(tmp);
		if (!current)
			return ;
	}
}

void	check_invalid_files(t_flag *flags, t_file **filelist)
{
	struct stat	dirstat;
	t_file	*current;
	t_file	*nextitem;
	t_file	*tmp;

	find_first_valid(flags, filelist);
	if (!(*filelist))
		return ;
	current = *filelist;
	nextitem = current->next;
	while (nextitem)
	{
		if ((lstat(nextitem->name, &dirstat)) == -1)
		{
			printf("wrong file %s\n", nextitem->name);
			tmp = nextitem;
			current->next = nextitem->next;
			nextitem = nextitem->next;
			free(tmp);
			continue;
		}
		current = current->next;
		nextitem = nextitem->next;
	}
	ft_putchar('\n');
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
