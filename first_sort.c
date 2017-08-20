#include "ft_ls.h"

static int	should_be_first(t_file *newitem, t_file *current)
{
	if (!(current))
		return (1);
	else if ((ft_strcmp(newitem->name, current->name)) < 0)
		return (1);
	return (0);
}

void		first_sort(const char *av, t_file **filelist)
{
	t_file	*arg;
	t_file	*current;
	t_file	*newitem;

	current = *filelist;
	arg = tfilenew((char *)av);
	if (should_be_first(arg, current))
	{
		tfile_add_first(arg, filelist);
		return ;
	}
	while (current->next)
	{
		if ((ft_strcmp(arg->name, current->next->name)) < 0)
		{
			tfile_add_after(arg, current);
			return ;
		}
		current = current->next;
	}
	tfile_add_last(arg, current);
}