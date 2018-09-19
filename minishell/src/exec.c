/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:50:25 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:37:52 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "stringmy.h"
#include "arraymy.h"
#include "minishell1.h"

int		control_default_cmd(char **argv, char ***env)
{
	if (my_strcmp(argv[0], "exit") == 0)
		return (command_exit(argv, *env));
	else if (my_strcmp(argv[0], "setenv") == 0)
		return (command_setenv(argv, env));
	else if (my_strcmp(argv[0], "unsetenv") == 0)
		return (command_unsetenv(argv, env));
	else if (my_strcmp(argv[0], "env") == 0)
		return (command_env(argv, env));
	else if (my_strcmp(argv[0], "cd") == 0)
		return (command_cd(argv, env));
	return (0);
}

int		child(char **argv, char **env, int ifd, int ofd)
{
	dup2(ifd, 0);
	dup2(ofd, 1);
	if (execve(get_bin_path(argv[0], env), argv, env) < 0)
	{
		my_puterror(argv[0]);
		my_puterror(": command not found\n");
		return (0);
	}
	close(ifd);
	close(ofd);
	return (1);
}

int		execute_command(char *cmd, char ***env, int ifd, int ofd)
{
	char		**argv;
	pid_t		pid;

	if ((argv = my_parse_args(cmd, *env)) != NULL)
		if (!control_default_cmd(argv, env))
		{
			if ((pid = fork()) >= 0)
			{
				if (pid == 0)
				{
					if (!child(argv, *env, ifd, ofd))
					{
						my_free_array(argv);
						exit(EXIT_FAILURE);
					}
					exit(EXIT_SUCCESS);
				}
				else
				{
					my_free_array(argv);
					return (pid);
				}
			}
		}
	return (-1);
}
