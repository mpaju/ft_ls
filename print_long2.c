/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:06:23 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 17:48:05 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_groupname(t_flag *flags, t_dir *item)
{
	struct group	*grpinfo;
	int				strlen;

	grpinfo = getgrgid(item->stat.st_gid);
	strlen = ft_strlen(grpinfo->gr_name);
	ft_putstr(grpinfo->gr_name);
	ft_print_chars(' ', flags->grouplen - strlen);
}

void	print_filesize(t_dir *item)
{
	int		strlen;
	char	*str;

	if (S_ISBLK(item->stat.st_mode) || S_ISCHR(item->stat.st_mode))
	{
		str = ft_itoa((int)major(item->stat.st_rdev));
		strlen = ft_strlen(str);
		ft_print_chars(' ', 5 - strlen);
		ft_putstr(str);
		ft_putchar(',');
		str = ft_itoa((int)minor(item->stat.st_rdev));
		strlen = ft_strlen(str);
		ft_print_chars(' ', 5 - strlen);
		ft_putstr(str);
	}
	else
	{
		str = ft_itoa((int)item->stat.st_size);
		strlen = ft_strlen(str);
		ft_print_chars(' ', 7 - strlen);
		ft_putstr(str);
	}
}

void	print_modtime(t_flag *flags, t_dir *item)
{
	char	**itemtime;

	itemtime = ft_strsplit(ft_strdup(ctime(&item->stat.st_mtime)), ' ');
	ft_putstr(itemtime[1]);
	ft_strlen(itemtime[2]) < 2 ? ft_putstr("  ") : ft_putstr(" ");
	ft_putstr(itemtime[2]);
	ft_putchar(' ');
	itemtime[4][ft_strlen(itemtime[4]) - 1] = '\0';
	if (flags->flag_ut)
	{
		ft_putstr(itemtime[3]);
		ft_putchar(' ');
		ft_putstr(itemtime[4]);
	}
	else if (time(NULL) - item->stat.st_mtime < SIX_MONTHS_SEC)
	{
		itemtime[3][ft_strlen(itemtime[3]) - 3] = '\0';
		ft_putstr(itemtime[3]);
	}
	else
	{
		ft_putchar(' ');
		ft_putstr(itemtime[4]);
	}
}

void	print_filename(t_dir *item)
{
	ft_putstr(item->bname);
}

void	print_link_data(t_dir *item)
{
	char		*str;

	ft_putstr(" -> ");
	str = (char *)ft_memalloc(sizeof(char) * BUFFSIZE);
	if ((readlink(item->name, str, sizeof(char) * BUFFSIZE)) == -1)
		return ;
	ft_putstr(str);
}
