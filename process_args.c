/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:42:58 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 15:48:21 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		process_args(int ac, const char **av, t_flag *flags, \
		t_file **filelist)
{
	int			i;

	i = 1;
	av++;
	while (*av)
	{
		if (*av[0] == '-' && i < ac)
			process_flags(*av, flags);
		else
			break ;
		av++;
		i++;
	}
	flags->first_line = 1;
	if (ac - i == 1 || ac == 1)
		flags->single_dir = 1;
	while (*av && i < ac)
	{
		first_sort(*av, filelist);
		av++;
		i++;
	}
}