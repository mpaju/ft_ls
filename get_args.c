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

void	path_process(const char *av, t_list *paths)
{
	ft_strcpy(paths->content, (char *)av);
	paths->content_size = sizeof((char *)paths->content);
	return ;
}

int		get_args(int ac, const char **av, t_flag *flags, t_list *paths)
{
	int		i;
	
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
	while (i < ac)
	{
		path_process(*av, paths);
	}
	return (0);
}


