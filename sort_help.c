/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:43:28 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 20:01:00 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	sort_by_size(t_dir **item, t_dir **list)
{
	t_dir	*current;
	t_dir	**link;

	current = *list;
	link = list;
	while (current)
	{
		if (((*item)->stat.st_size > current->stat.st_size))
		{
			*link = *item;
			(*item)->next = current;
			return ;
		}
		current = current->next;
		link = &(*link)->next;
	}
	*link = *item;
}

void	sort_by_name(t_dir **item, t_dir **list)
{
	t_dir	*current;
	t_dir	**link;

	current = *list;
	link = list;
	while (current)
	{
		if ((has_lower_alpha_value((*item)->bname, current->bname)))
		{
			*link = *item;
			(*item)->next = current;
			return ;
		}
		current = current->next;
		link = &(*link)->next;
	}
	*link = *item;
}

void	sort_by_time(t_dir **diritem, t_dir **arglist)
{
	t_dir	**link;
	t_dir	*current;

	link = arglist;
	current = *arglist;
	while (current)
	{
		if (is_modified_later((*diritem)->time, current->time))
		{
			*link = *diritem;
			(*diritem)->next = current;
			return ;
		}
		current = current->next;
		link = &(*link)->next;
	}
	*link = *diritem;
}
