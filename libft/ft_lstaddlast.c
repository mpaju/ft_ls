/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:11:11 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 14:29:46 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstaddlast(t_list **alst, t_list *newlist)
{
	if (!alst && !newlist)
		return (0);
	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	newlist->next = NULL;
	(*alst)->next = newlist;
	return (1);
}
