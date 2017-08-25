#include "ft_ls.h"

char	*get_basename(char *name)
{
	int	size;

	size = ft_strlen(name);
	size--;
	while (name[size])
	{
		if (name[size] == '/')
			return (&name[size + 1]);
		size--;
	}
	return (name);
}