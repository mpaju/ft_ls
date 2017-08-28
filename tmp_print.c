#include "ft_ls.h"

void	print_tdir_items(t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	printf("\n%s:\n", current->path);
	while (current)
	{
		printf("%s\n",current->bname);
		current = current->next;
	}
	current = *arglist;
	while (current)
	{
		if (current->subfiles)
			print_tdir_items(&current->subfiles);
		current = current->next;
	}
}