#include "ft_ls.h"

void	print_tdir_items(t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	printf("\n%s\n", current->path);
	while (current)
	{
		printf("%s\n",current->bname);
		if (current->subdir)
			print_tdir_items(&current->subdir);
		current = current->next;
	}
}