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

int	sort_by_alpha(t_dir *dirlist, t_dir *newdir)
{
	return (ft_strcmp(dirlist->name, newdir->name) > 0);
}

int	sort_by_time(t_dir *dirlist, t_dir *newdir)
{
	if (dirlist->time == newdir->time)
		return (sort_by_alpha(dirlist, newdir));
	return (dirlist->time > newdir->time);
}

void	lstlink(t_flag *flags, t_dir **dirlist, t_dir *newdir)
{
	t_dir	*prev;
	t_dir	*curr;

	curr = newdir;
	prev = NULL;
	while (curr)
	{
		if (flags->flag_t)
		{
			if (((sort_by_time(*dirlist, newdir) > 0))) //vajab debuggimist
			{
				if (prev == NULL)
				{
					newdir->next = *dirlist;
					*dirlist = newdir;
				}
				else
				{
					newdir->next = prev->next;
					prev->next = newdir;
				}
			}
		}
		else
		{
			if (((sort_by_alpha(*dirlist, newdir)) > 0))
			{
				if (prev == NULL)
				{
					newdir->next = *dirlist;
					*dirlist = newdir;
				}
				else
				{
					newdir->next = prev->next;
					prev->next = newdir;
				}
			}
		}
		prev = curr;
		curr = curr->next;
	}
}

void	sort_dir(t_flag *flags, t_dir **dirlist, t_dir *newdir)
{
	if (*dirlist == NULL)
	{
		dirlist = &newdir;
		return ;
	}
	// siin vaja debuggimist, ei tea kas aadressi teema korras (kas dirlisti aadress jaabki listi algusesse, voi jamab
	lstlink(flags, dirlist, newdir);
	/*
	else if (flags->flag_t)
		sort_by_time(dirlist, newdir);
	else
		sort_by_alpha(dirlist, newdir);
	*/
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
	dirlist = newdir;
	while (*av)
	{
		if ((stat(*av, &dirstat)) == -1)
			//paths = tdirnew((char *)*av, -1);
			perror(*av);
		else
			newdir = tdirnew((char *) *av, dirstat.st_mtime);
		sort_dir(flags, &dirlist, newdir);
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


