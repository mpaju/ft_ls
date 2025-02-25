/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_args_printing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 13:57:46 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 16:41:23 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	find_first_valid(t_file **filelist)
{
	struct stat	dirstat;
	t_file		*current;
	t_file		*tmp;

	current = *filelist;
	if (!current)
		return ;
	while ((lstat(current->name, &dirstat)) == -1)
	{
		ft_putstr("ls: ");
		perror(current->name);
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
	if (flags->flag_l)
		print_long_format(flags, current);
	else
		ft_putendl(current->name);
	flags->first_line = 0;
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
		*link = NULL;
	}
}

void	print_invalid_files(t_file **filelist)
{
	struct stat	dirstat;
	t_file		*current;
	t_file		*nextitem;
	t_file		*tmp;

	find_first_valid(filelist);
	if (!(*filelist))
		return ;
	current = *filelist;
	nextitem = current->next;
	while (nextitem)
	{
		if ((lstat(nextitem->name, &dirstat)) == -1)
		{
			ft_putstr("ls: ");
			perror(nextitem->name);
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
