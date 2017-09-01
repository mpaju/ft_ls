#include "ft_ls.h"

/*
void	print_single_dir(t_flag *flags, t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	if (!current)
		return ;
	while (current)
	{
		printf("%s\n", current->bname);
		if (!current->next && !current->subfiles)
			flags->last_line = 1;
		current = current->next;
	}
	if (!flags->last_line)
		ft_putchar('\n');
	print_arglist(flags, arglist);
}

void	print_tdir_items(t_flag *flags, t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	// if (!current)
	// 	return ;
	while (current)
	{
		if (current->error_nr)
		{
			printf("ls: %s: ", current->bname);
			printf("%s\n", strerror(current->error_nr));
		}
		else
			printf("%s\n",current->bname);
		current = current->next;
	}
	//while (current)
	//{
	//	current = current->next;
	//}

}



void	print_arglist(t_flag *flags, t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	while (current)
	{
		if (current->subfiles)
		{
			printf("%s:\n", current->name);
			print_tdir_items(flags, &current->subfiles);
			ft_putchar('\n');
			print_arglist(flags, &current->subfiles);
		}
		current = current->next;
	}
}
*/

static void	print_subs(t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	while (current)
	{
		if (current->error_nr)
			printf("ls: %s\n", strerror(current->error_nr));
		else
			printf("%s\n", current->bname);
		current = current->next;
	}
}

void	print_arglist(t_flag *flags, t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	if (current->subfiles)
	{
		if (!flags->first_line)
			printf("X\n");
		printf("%s:\n", current->name);
		flags->first_line = 0;
		print_subs(&current->subfiles);
	// 	print_arglist(flags, &current->subfiles);
	}
	else
	{
		if (!flags->first_line)
			printf("X\n");
		printf("%s:\n", current->name);
		flags->first_line = 0;
	}
	// if (current->next)
	// 	print_arglist(flags, &current->next);

}

void	print_single_dir(t_flag *flags, t_dir **arglist)
{
	print_subs(&(*arglist)->subfiles);
	flags->first_line = 0;
	flags->single_dir = 0;
	// print_arglist(flags, &(*arglist)->subfiles);
}