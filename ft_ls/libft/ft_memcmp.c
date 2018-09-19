/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:41:42 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 20:56:48 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*dest;
	const unsigned char	*src;

	dest = (unsigned char*)s1;
	src = (unsigned char*)s2;
	while (n > 0)
	{
		if (*dest != *src)
			return (*dest - *src);
		else
		{
			dest++;
			src++;
			n--;
		}
	}
	return (0);
}
