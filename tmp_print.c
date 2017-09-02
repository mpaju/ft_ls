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
void	print_total_blocks(t_dir *item)
{
	unsigned int	total;

	total = 0;
	while (item)
	{
		total += item->stat.st_blocks;
		item = item->next;
	}
	ft_putstr("total ");
	ft_putstr(ft_itoa(total));
	ft_putchar('\n');
}
void	print_rights(mode_t mode)
{

	mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	mode & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	mode & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	mode & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
}
void	print_ftype_and_rights(t_dir *item)
{
	mode_t	mode;

	mode = item->stat.st_mode;
	print_type(mode);
	print_rights(mode);
	ft_putchar(' ');

}

void	print_linkcount(t_dir *item)
{
	ft_putstr(ft_itoa(item->stat.st_nlink));
	ft_putchar(' ');
}

void	print_username(t_flag *flags, t_dir *item)
{
	struct passwd	*pwinfo;
	int				strlen;

	pwinfo = getpwuid(item->stat.st_uid);
	strlen = ft_strlen(pwinfo->pw_name);
	ft_putstr(pwinfo->pw_name);
	ft_print_chars(' ', flags->userlen - strlen);
	ft_putchar(' ');
}



void	print_groupname(t_flag *flags, t_dir *item)
{
	struct group	*grpinfo;
	int				strlen;

	grpinfo = getgrgid(item->stat.st_gid);
	strlen = ft_strlen(grpinfo->gr_name);
	ft_putstr(grpinfo->gr_name);
	ft_print_chars(' ', flags->grouplen - strlen);
	ft_putchar(' ');
}

void	print_filesize(t_dir *item)
{
	int		strlen;
	char	*value;

	if (S_ISBLK(item->stat.st_mode) || S_ISCHR(item->stat.st_mode))
	{
		value = ft_itoa((int)major(item->stat.st_rdev));
		strlen = ft_strlen(value);
		ft_print_chars(' ', 5 - strlen);
		ft_putstr(value);
		ft_putchar(',');
		value = ft_itoa((int)minor(item->stat.st_rdev));
		strlen = ft_strlen(value);
		ft_print_chars(' ', 5 - strlen);
		ft_putstr(value);
		ft_putchar(' ');
	}
	else
	{
		ft_putstr("filesize");
		ft_putchar(' ');
	}
}

void print_modtime(t_dir *item)
{
	char	**itemtime;

	itemtime = ft_strsplit(ft_strdup(ctime(&item->stat.st_mtime)), ' ');
	ft_putstr(itemtime[1]);
	ft_strlen(itemtime[2]) < 2 ? ft_putstr("  ") : ft_putstr(" ");
	ft_putstr(itemtime[2]);
	ft_putchar(' ');
	itemtime[4][ft_strlen(itemtime[4]) - 1] = '\0';
	itemtime[3][ft_strlen(itemtime[3]) - 3] = '\0';
	if (time(NULL) - item->stat.st_mtime < SIX_MONTHS_SEC)
		ft_putstr(itemtime[3]);
	else
	{
		ft_putstr(itemtime[4]);
		ft_putchar(' ');
	}
	ft_putchar(' ');
}

void	print_filename(t_dir *item)
{
	ft_putstr(item->bname);
	ft_putchar(' ');
}


void	print_long_format(t_flag *flags, t_dir *item)
{
	print_ftype_and_rights(item);
	print_linkcount(item);
	print_username(flags, item);
	print_groupname(flags, item);
	print_filesize(item);
	print_modtime(item);
	print_filename(item);
	ft_putchar('\n');
}

static void	print_subs(t_flag *flags, t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	if (flags->flag_l && current)
		print_total_blocks(current);
	while (current)
	{
		if (current->error_nr)
			printf("ls: %s\n", strerror(current->error_nr));
		else if (flags->flag_l)
			print_long_format(flags, current);
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
		print_subs(flags, &current->subfiles);
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
	print_subs(flags, &(*arglist)->subfiles);
	flags->first_line = 0;
	flags->single_dir = 0;
	// print_arglist(flags, &(*arglist)->subfiles);
}