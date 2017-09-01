#include "ft_ls.h"

void		process_flags(const char *av, t_flag *flags)
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
			wrong_flag(av);
		av++;
	}
	flags->first_line = 1;
}