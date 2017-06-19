#include "libft.h"

int	ft_chrpos(char *str, char x)
{
	int	c;

	c = 1;
	while (*str)
	{
		if (*str == x)
			return (c);
		c++;
		str++;
	}
	return (0);
}