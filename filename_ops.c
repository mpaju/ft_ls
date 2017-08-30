#include "ft_ls.h"

char	*get_basename(char *name)
{
	int	size;
	char	*ret;
	size = ft_strlen(name);
	size--;
	while (name[size])
	{
		if (name[size] == '/')
		{
			fflush(stdout);
			ret = ft_strdup(&(name[size + 1]));
			return (ret);
		}
		size--;
	}
	return (name);
}