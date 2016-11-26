/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 22:52:59 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/13 05:31:46 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb - 1 > 0)
		{
			ft_putchar('-');
			ft_putnbr(-(nb + 1) / 10);
			ft_putnbr(8);
		}
		else
		{
			ft_putchar('-');
			nb *= -1;
		}
	}
	if (nb <= 9 && nb >= 0)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
