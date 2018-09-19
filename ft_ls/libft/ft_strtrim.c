/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:51:49 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/08 21:18:57 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	begin = 0;
	end = ft_strlen(s) - 1;
	while (begin < ft_strlen(s) && ft_isspace(s[begin]))
		begin++;
	while (end > begin && ft_isspace(s[end]))
		end--;
	len = end - begin + 1;
	str = ft_strsub(s, begin, len);
	return (str);
}
