/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ftype_and_rights.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:06:12 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 15:06:16 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_type(mode_t mode)
{
	S_ISREG(mode) ? ft_putchar('-') : 0;
	S_ISDIR(mode) ? ft_putchar('d') : 0;
	S_ISLNK(mode) ? ft_putchar('l') : 0;
	S_ISBLK(mode) ? ft_putchar('b') : 0;
	S_ISCHR(mode) ? ft_putchar('c') : 0;
	S_ISFIFO(mode) ? ft_putchar('p') : 0;
	S_ISSOCK(mode) ? ft_putchar('s') : 0;
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
}
