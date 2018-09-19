/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 21:32:59 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 20:55:08 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char cast;

	cast = (unsigned char)c;
	str = (unsigned char*)s;
	while (n > 0)
	{
		if (*str != cast)
			str++;
		else
			return (str);
		n--;
	}
	return (0);
}
