/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:43:28 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 14:43:34 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	insert_last_pos(t_dir **diritem, t_dir **arglist)
{
	t_dir	*current;

	current = *arglist;
	while (current->next)
		current = current->next;
	current->next = *diritem;
}

int		is_modified_later(int val1, int val2)
{
	if (val1 > val2)
		return (1);
	return (0);
}

int		has_lower_alpha_value(char *str1, char *str2)
{
	if ((ft_strcmp(str1, str2)) < 0)
		return (1);
	return (0);
}
