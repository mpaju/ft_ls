/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 16:17:10 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 16:50:19 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_recursion(t_flag *flags, t_dir *current)
{
	while (current)
	{
		if (flags->flag_ur && S_ISDIR(current->stat.st_mode) && \
			ft_strcmp(current->bname, ".") && ft_strcmp(current->bname, ".."))
			read_dir_and_print(flags, &current);
		current = free_tdir_and_return_next(current);
	}
}

void	read_dir_and_print(t_flag *flags, t_dir **arg)
{
	DIR				*dir;
	struct dirent	*open_dir;
	t_dir			*item;

	if ((dir = opendir((*arg)->name)) != NULL)
	{
		while ((open_dir = readdir(dir)) != NULL)
		{
			if ((!flags->flag_a && ft_strncmp(open_dir->d_name, ".", 1)) \
				|| flags->flag_a)
			{
				item = tdirnew(flags, get_filename((*arg)->name, \
					open_dir->d_name));
				sort_stuff(flags, &item, &(*arg)->subfiles);
			}
		}
		closedir(dir);
		if (flags->flag_r && (*arg)->subfiles)
			reverse_tdir_list(&(*arg)->subfiles);
		flags->single_dir ? print_single(flags, arg) : print_multi(flags, arg);
		check_recursion(flags, (*arg)->subfiles);
	}
	else
		print_error(NAME, (*arg)->name);
}

void	get_dir_data(t_flag *flags, t_dir **arglist)
{
	t_dir			*current;

	current = *arglist;
	while (current)
	{
		read_dir_and_print(flags, &current);
		current = free_tdir_and_return_next(current);
	}
	exit(1);
}

void	ft_ls(t_flag *flags, t_file **filelist)
{
	t_dir	*arglist;

	arglist = NULL;
	if (!*filelist)
		exit(0);
	sort_filelist_into_arglist(flags, filelist, &arglist);
	print_and_remove_normal_files(flags, &arglist);
	if (!arglist)
		exit(1);
	get_dir_data(flags, &arglist);
	return ;
}
