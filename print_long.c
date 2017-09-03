/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:14:46 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 15:14:48 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	print_linkcount(t_dir *item)
{
	int		strlen;
	char	*str;

	str = ft_itoa(item->stat.st_nlink);
	strlen = ft_strlen(str);
	ft_print_chars(' ', 4 - strlen);
	ft_putstr(str);
}

void	print_username(t_flag *flags, t_dir *item)
{
	struct passwd	*pwinfo;
	int				strlen;

	pwinfo = getpwuid(item->stat.st_uid);
	strlen = ft_strlen(pwinfo->pw_name);
	ft_putstr(pwinfo->pw_name);
	ft_print_chars(' ', flags->userlen - strlen);
}

void	print_long_format(t_flag *flags, t_dir *item)
{
	print_ftype_and_rights(item);
	ft_putchar(' ');
	print_linkcount(item);
	ft_putchar(' ');
	print_username(flags, item);
	ft_putchar(' ');
	print_groupname(flags, item);
	ft_putchar(' ');
	print_filesize(item);
	ft_putchar(' ');
	print_modtime(item);
	ft_putchar(' ');
	print_filename(item);
	if (S_ISLNK(item->stat.st_mode))
		print_link_data(item);
	ft_putchar('\n');
}
