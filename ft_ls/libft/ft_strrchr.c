/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:02:19 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 21:16:20 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*var;
	int		n;

	n = ft_strlen(s);
	var = 0;
	while (n >= 0)
	{
		if (*s == (char)c)
			var = (char*)s;
		s++;
		n--;
	}
	return (var);
}
