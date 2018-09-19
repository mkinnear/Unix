/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:50:15 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 21:08:32 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		i;
	int		l;
	char	*dest;

	i = 0;
	l = ft_strlen((char*)str);
	dest = (char*)malloc((sizeof(char) * l) + 1);
	if (!dest)
		return (NULL);
	while (str[i] && str)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
