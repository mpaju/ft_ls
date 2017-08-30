#include "ft_ls.h"

void	print_single_dir(t_flag *flags, t_dir **arglist)
{
	if ((*arglist)->subfiles)
		/*printf("%s\n", (*arglist)->bname);
	if ((*arglist)->subfiles)*/
		print_tdir_items(flags, &(*arglist)->subfiles);
}

void	print_tdir_items(t_flag *flags, t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	if (!current)
		return ;
	printf("%s:\n", current->path);
	while (current)
	{
		if (current->error_nr)
		{
			printf("%s: ", current->bname);
			printf("%s\n", strerror(current->error_nr));
			current = current->next;
			continue;
		}
		printf("%s\n",current->bname);
		current = current->next;
	}
	current = *arglist;
	//while (current)
	//{
	if (current->subfiles)
		print_tdir_items(flags, &current->subfiles);
	if (current->next)
		print_tdir_items(flags, &current->next);
	//	current = current->next;
	//}

}