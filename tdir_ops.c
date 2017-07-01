#include "ft_ls.h"

t_dir	*tdirnew(char *name, time_t time)
{
	t_dir	*ret;

	if (!(ret = (t_dir *)ft_memalloc(sizeof(*ret))))
		return (NULL);
	if (name)
	{
		if (!(ret->name = (char *)ft_memalloc(*name)))
			return (NULL);
		ft_strcpy(ret->name, name);
	}
	if (time)
	{
		if (!(ret->time = (time_t)ft_memalloc(sizeof(time))))
			return (NULL);
		ft_memcpy((void *)ret->time, (void *)time, sizeof(time));
	}
	if (!name && !time)
	{
		ret->name = NULL;
		ret->time = 0;
	}
	return (ret);
}
