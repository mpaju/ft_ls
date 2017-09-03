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
			ret = ft_strdup(&(name[size + 1]));
			return (ret);
		}
		size--;
	}
	return (ft_strdup(name));
}

char	*get_pathname(char *name)
{
	int	size;

	size = ft_strlen(name);
	size--;
	while ((name[size]) != '/' && size != -1)
		size--;
	if (size == -1)
		return (ft_strjoin(name, "/"));
	return (ft_strncpy(ft_strnew(size + 2), name, size + 1));
}

char	*get_filename(char *path, char *name)
{
	char	*str;
	char	*retstr;

	str = ft_strjoin("/", name);
	retstr = ft_strjoin(path, str);
	free(str);
	return (retstr);
}
