#include "ft_ls.h"
#include "libft/libft.h"
void	ft_ls(t_dir *paths, t_flag *flags)
{
	DIR				*homedir;
	struct dirent	*readhdir;
	struct stat		for_time;
	char			*tmp;

	if (!(homedir = opendir(".")))
		return ;


}
