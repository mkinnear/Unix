/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:40:36 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:38:18 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minishell1.h"
#include "stringmy.h"
#include "arraymy.h"

int		exec_cmds_by_order(char *cmd, char ***env)
{
	char	**command_list;
	int		i;

	if ((command_list = my_split_string(cmd, ";", 1)) != NULL)
	{
		i = 0;
		while (command_list[i] != NULL)
		{
			if (!exec_command_pipe(command_list[i], env))
			{
				my_puterror("mysh: I/O error.\n");
				return (my_free_array(command_list) && 0);
			}
			i = i + 1;
		}
		return (my_free_array(command_list) && 1);
	}
	return (0);
}
