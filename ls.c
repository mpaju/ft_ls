#include "ft_ls.h"
#include "libft/libft.h"
void	ls(t_list *paths, t_flag *flags)
{
	DIR				*homedir;
	struct dirent	*readhdir;
	struct stat		for_time;
	char			*tmp;

	if (!(homedir = opendir(".")))
		return 0;


}
