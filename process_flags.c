/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:43:17 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 15:36:53 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		process_flags(const char *av, t_flag *flags)
{
	int	av_strlen;

	if (!(av) || !(flags))
		return ;
	av++;
	av_strlen = ft_strlen(av);
	while (*av && av_strlen--)
	{
		if (*av == 'l')
			flags->flag_l = 1;
		else if (*av == 'a')
			flags->flag_a = 1;
		else if (*av == 'r')
			flags->flag_r = 1;
		else if (*av == 'R')
			flags->flag_ur = 1;
		else if (*av == 't')
			flags->flag_t = 1;
		else
			wrong_flag(av);
		av++;
	}
}
