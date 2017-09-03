#include "libft.h"

void	ft_print_chars(char chr, int count)
{
	if (!chr || count <= 0)
		return ;
	while (count--)
		ft_putchar(chr);
}