/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 13:42:03 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 13:43:46 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	wrong_flag(const char *av)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd((char)*av, 2);
	ft_putstr_fd("\nusage: ls [-alrRt] [file ...]\n", 2);
	exit(1);
}

void	check_empty_arg(int ac, const char **av)
{
	while (ac > 1)
	{
		if (*av == '\0')
		{
			ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
			exit(1);
		}
		ac--;
		av++;
	}
}
