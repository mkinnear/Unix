/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 22:24:24 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 20:58:42 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*s1;
	const char	*s2;

	s1 = (char*)dst;
	s2 = (char*)src;
	if (s1 > s2)
	{
		while (len > 0)
		{
			len--;
			s1[len] = s2[len];
		}
	}
	else
		ft_memcpy(s1, s2, len);
	return (s1);
}
