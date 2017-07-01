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

int		get_args(int ac, const char **av, t_flag *flags, t_dir *paths)
{
	int			i;
	struct stat	dirstat;
	time_t		time;

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
	if ((stat(*av, &dirstat)) == -1)
		paths = tdirnew((char *)*av, -1);
	else
		paths = tdirnew((char *) *av, sizeof(av));
	while (i + 1 < ac)
	{
		av++;
		i++;
		paths->next = ft_lstnew(av, sizeof(av));
	}
	return (0);
}


