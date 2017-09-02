#include "ft_ls.h"

t_dir	*tdirnew(t_flag *flags, char *name)
{
	t_dir			*ret;
	struct passwd	*pwinfo;
	struct group	*grpinfo;

	if (!(ret = (t_dir *)ft_memalloc(sizeof(*ret))))
		return (NULL);
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
		ret->time = ret->stat.st_mtime;
		pwinfo = getpwuid(ret->stat.st_uid);
		if (flags->userlen < ft_strlen(pwinfo->pw_name))
			flags->userlen = ft_strlen(pwinfo->pw_name);
		grpinfo = getgrgid(ret->stat.st_gid);
		if (flags->grouplen < ft_strlen(grpinfo->gr_name))
			flags->grouplen = ft_strlen(grpinfo->gr_name);
	}
	else
		ret->error_nr = errno;
	ret->bname = get_basename(ret->name);
	ret->path = get_pathname(ret->name);
	return (ret);
}
