#include "ft_ls.h"

//void	swap_nodes()

int	has_lower_int_value(int val1, int val2)
{
	if (val1 < val2)
		return (1);
	return (0);
}

int	has_lower_alpha_value(char *str1, char *str2)
{
	if ((ft_strcmp(str1, str2)) < 0)
		return (1);
	return (0);
}