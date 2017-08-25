#include "ft_ls.h"

void	find_first_valid(t_file **filelist)
{
	struct stat	dirstat;
	t_file	*current;
	t_file	*tmp;

	current = *filelist;
	while ((lstat(current->name, &dirstat)) == -1)
	{
		printf("not valid: %s\n", current->name);
		*filelist = current->next;
		tmp = current;
		current = current->next;
		free(tmp);
		if (!current)
			return ;
	}
}

void	print_file_info(t_flag *flags, t_dir *current)
{
	printf("print_file_info: %s\n", current->name);
}

void	print_and_remove_normal_files(t_flag *flags, t_dir **arglist)
{
	t_dir	**link;
	t_dir	*current;

	link = arglist;
	current = *arglist;
	while (current->next)
	{
		if (!(S_ISDIR(current->stat.st_mode)))
		{
			print_file_info(flags, current);
			current = current->next;
			free(*link);
			*link = current;
			continue;
		}
		current = current->next;
		link = &(*link)->next;
	}
	if (!(S_ISDIR(current->stat.st_mode)))
	{
		print_file_info(flags, current);
		free(current);
		arglist = NULL;
		exit (1);
	}
}

void	print_invalid_files(t_flag *flags, t_file **filelist)
{
	struct stat	dirstat;
	t_file	*current;
	t_file	*nextitem;
	t_file	*tmp;

	find_first_valid(filelist);
	if (!(*filelist))
		return ;
	current = *filelist;
	nextitem = current->next;
	while (nextitem)
	{
		if ((lstat(nextitem->name, &dirstat)) == -1)
		{
			printf("wrong file %s\n", nextitem->name);
			tmp = nextitem;
			current->next = nextitem->next;
			nextitem = nextitem->next;
			free(tmp);
			continue;
		}
		current = current->next;
		nextitem = nextitem->next;
	}
}