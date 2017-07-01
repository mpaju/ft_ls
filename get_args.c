#include "ft_ls.h"
#include "libft/libft.h"

void		flag_process(const char *av, t_flag *flags)
{
	int	av_strlen;

	if (!(av) || !(flags))
		return ;
	av++;
	av_strlen = ft_strlen(av);
	while (*av && av_strlen--)
	{
		if (*av == 'l')
			flags->flag_l = 1;
		else if (*av == 'a')
			flags->flag_a = 1;
		else if (*av == 'r')
			flags->flag_r = 1;
		else if (*av == 'R')
			flags->flag_R = 1;
		else if (*av == 't')
			flags->flag_t = 1;
		else
		{
			ft_putstr("Usage ./ft_ls -larRt path");
			exit (0);
		}
		av++;
	}
}

void	sort_dir(t_flag *flags, t_dir *dirlist, t_dir *newdir)
{
	if (dirlist == NULL)
		dirlist = newdir;
		// siin vaja debuggimist, ei tea kas aadressi teema korras
	else if (flags->flag_t)
		sort_by_time(dirlist, newdir);
	else
		sort_by_alpha(dirlist, newdir);
}

int		get_args(int ac, const char **av, t_flag *flags, t_dir *dirlist)
{
	int			i;
	struct stat	dirstat;
	time_t		time;
	t_dir		*newdir;

	i = 1;
	av++;
	while (*av[0] == '-' && i < ac)
	{
		flag_process(*av, flags);
		av++;
		i++;
		if (*av == '\0')
			break;
	}
	// flaggi teema peaks korras olema
	if ((stat(*av, &dirstat)) == -1)
		perror(*av);
		// ei tea kas tuleb oige error
	else
		newdir = tdirnew((char *) *av, dirstat.st_mtime);
	av++;
	while (*av)
	{
		if ((stat(*av, &dirstat)) == -1)
			//paths = tdirnew((char *)*av, -1);
			perror(*av);
		else
			newdir = tdirnew((char *) *av, dirstat.st_mtime);
		sort_dir(flags, dirlist, newdir);
		av++;
	}
	/*while (i + 1 < ac)
	{
		av++;
		i++;
		paths->next = ft_lstnew(av, sizeof(av));
	}*/
	return (0);
}


