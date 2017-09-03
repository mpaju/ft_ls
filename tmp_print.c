/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:15:41 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 15:50:43 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
			ft_putchar('\n');
		ft_putstr(current->name);
		ft_putendl(":");
		flags->first_line = 0;
		print_subs(flags, &current->subfiles);
	}
	else
	{
		if (!flags->first_line)
			ft_putchar('\n');
		ft_putstr(current->name);
		flags->first_line = 0;
	}
}

void	print_single_dir(t_flag *flags, t_dir **arglist)
{
	print_subs(flags, &(*arglist)->subfiles);
	flags->first_line = 0;
	flags->single_dir = 0;
}
