/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 02:55:47 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/23 18:34:20 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *str1, const char *str2, unsigned int n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	count;

	if (!n)
		return (0);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	count = 1;
	while ((*s1 == *s2 && (*(s1 + 1) != '\0' || *(s2 + 1) != '\0')) && \
			count < n)
	{
		s1++;
		s2++;
		count++;
	}
	return (*s1 - *s2);
}
