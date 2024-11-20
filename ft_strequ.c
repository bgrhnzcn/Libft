/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:37:11 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/09/12 00:51:15 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (*s1)
	{
		if (*s1 - *s2)
			return (false);
		s2++;
		s1++;
	}
	return (true);
}
