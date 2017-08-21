#include "ft_ls.h"

void	ft_ls(t_flag *flags, t_file **filelist)
{
	t_dir	*arglist;

	sort_filelist_into_arglist(flags, filelist, &arglist);
	return ;
}
