/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:36:32 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/04 09:26:05 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst == NULL || alst == NULL || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_bzero((void *)*alst, sizeof(*alst));
	free(*alst);
	*alst = NULL;
}
