#include "ft_ls.h"

t_dir	*tdirnew(char *name)
{
	t_dir	*ret;

	// if (!(ret = (t_dir *)ft_memalloc(sizeof(*ret))))
	// 	return (NULL);
	if (name)
	{
		// if (!(ret->name = (char *)ft_memalloc(*name)))
		// 	return (NULL);
		ret->name = ft_strdup(name);
	}
	else
		ret->name = NULL;
	if ((lstat(name, &ret->stat)) != -1)
	{
		ret->bname = get_basename(ret->name);
		ret->path = get_pathname(ret->name);
		ret->time = ret->stat.st_mtime;
	}
	else
	{
		ret->bname = get_basename(ret->name);
		ret->path = get_pathname(ret->name);
		ret->error_nr = errno;
	}
	return (ret);
}