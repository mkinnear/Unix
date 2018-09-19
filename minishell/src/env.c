/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:04:37 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:37:28 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stringmy.h"
#include "arraymy.h"
#include "minishell1.h"

int		my_getenv(char *name, char **env)
{
	int		i;
	char	*search;
	int		name_len;

	name_len = my_strlen(name) + 2;
	search = (char*)malloc(sizeof(char) * name_len);
	if (search != NULL)
	{
		my_strcpy(search, name);
		my_strcat(search, "=");
		i = 0;
		while (env[i] != NULL)
		{
			if (my_strncmp(env[i], search, name_len) == 0)
			{
				free(search);
				return (i);
			}
			i = i + 1;
		}
		free(search);
	}
	return (-1);
}

char	**my_setenv(char *name, char *value, char **env)
{
	int		i;
	int		total_len;
	char	*record;

	total_len = my_strlen(name) + my_strlen(value) + 2;
	record = (char*)malloc(sizeof(char) * total_len);
	if (record != NULL)
	{
		my_strcpy(record, name);
		my_strcat(record, "=");
		my_strcat(record, value);
		if ((i = my_getenv(name, env)) >= 0)
		{
			free(env[i]);
			env[i] = record;
		}
		else
			return (my_add_to_array(record, env));
	}
	return (env);
}

char	**my_unsetenv(char *name, char **env)
{
	int		i;

	if ((i = my_getenv(name, env)) >= 0)
		env = my_remove_from_array(i, env);
	return (env);
}
