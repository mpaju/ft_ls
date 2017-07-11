#include "ft_ls.h"

t_dir	*tdirnew(char *name, time_t time)
{
	t_dir	*ret;
	time_t	*rettimecopy;

	if (!(ret = (t_dir *)ft_memalloc(sizeof(*ret))))
		return (NULL);
	if (name)
	{
		if (!(ret->name = (char *)ft_memalloc(*name)))
			return (NULL);
		ft_strcpy(ret->name, name);
	}
	else
		ret->name = NULL;
	rettimecopy = &ret->time;
	if (time)
	{
		if (!(ret->time = (time_t)ft_memalloc(sizeof(time))))
			return (NULL);
		*rettimecopy = time;
		//ft_memcpy((void *)ret->time, (void *)time, sizeof(time_t));
	}
	else
		ret->time = 0;
	ret->subdir = NULL;
	ret->next = NULL;
	return (ret);
}
