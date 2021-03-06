/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:19:23 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:40:55 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "stringmy.h"
#include "arraymy.h"
#include "minishell1.h"

char	*try_path(char *filename, char *dir)
{
	int		total_len;
	char	*path;

	total_len = my_strlen(filename) + my_strlen(dir) + 2;
	path = (char*)malloc(sizeof(char) * total_len);
	if (path != NULL)
	{
		my_strcpy(path, dir);
		my_strcat(path, "/");
		my_strcat(path, filename);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		path = NULL;
	}
	return (path);
}

char	*get_bin_path(char *filename, char **env)
{
	int		i;
	char	*path;
	char	**a_path;
	char	*p_bin;

	path = NULL;
	if ((i = my_getenv("PATH", env)) >= 0)
		path = env[i] + 5;
	i = 0;
	if (path != NULL && (a_path = my_split_string(path, ":", 1)) != NULL)
	{
		i = 0;
		while (a_path[i] != NULL)
		{
			if ((p_bin = try_path(filename, a_path[i])) != NULL)
			{
				my_free_array(a_path);
				return (p_bin);
			}
			i = i + 1;
		}
	}
	return (filename);
}

char	*get_home_dir(char **env)
{
	int	i;

	if ((i = my_getenv("HOME", env)) >= 0)
		return (env[i] + 5);
	return (NULL);
}
