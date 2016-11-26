/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 22:52:59 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/13 07:02:15 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		if (nb - 1 > 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-(nb + 1) / 10, fd);
			ft_putnbr_fd(8, fd);
		}
		else
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
	}
	if (nb <= 9 && nb >= 0)
		ft_putchar_fd(nb + 48, fd);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
