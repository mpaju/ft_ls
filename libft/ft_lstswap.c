/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:39:16 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 14:41:11 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstswap(t_list *lst, t_list *prev)
{
	t_list	*tmp;

	if (!(lst) || !(prev))
		return (0);
	prev->next = lst->next;
	tmp = lst->next;
	lst->next = tmp->next;
	tmp->next = lst;
	return (1);
}
