/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 22:06:47 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 22:19:55 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(to_find) - 1;
	i = 0;
	if (to_find[0] == '\0')
		return ((char *)&str[0]);
	else
	{
		while (str[i] && i < n)
		{
			if (str[i] == to_find[0] && str[i + len] == to_find[len])
			{
				while (str[i + len] == to_find[len] && len > 0 && (i + len) < n)
					len--;
				if (len == 0)
					return ((char *)&str[i]);
				else
					return (NULL);
			}
			else
				i++;
		}
	}
	return (0);
}
