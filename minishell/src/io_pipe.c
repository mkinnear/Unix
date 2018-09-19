/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:44:47 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:38:48 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell1.h"
#include "stringmy.h"
#include "arraymy.h"

int		swapio(int pipefd[2], int myio[2])
{
	if (myio[0] != 0)
		close(myio[0]);
	if (myio[1] != 1)
		close(myio[1]);
	myio[0] = pipefd[0];
	if (pipe(pipefd) != 0)
		return (0);
	myio[1] = pipefd[1];
	return (1);
}

void	my_begin_pipe(int pipefd[2], int myio[2])
{
	myio[0] = 0;
	myio[1] = pipefd[1];
}

void	my_end_pipe(int myio[2])
{
	close(myio[1]);
	myio[1] = 1;
}

int		exec_command_pipe(char *cmd, char ***env)
{
	char	**pipes;
	int		i;
	int		pipefd[2];
	int		myio[2];
	int		pid;

	if ((pipes = my_split_string(cmd, "|", 1)) != NULL)
	{
		i = 0;
		if (pipe(pipefd) != 0)
			return (my_free_array(pipes) && 0);
		my_begin_pipe(pipefd, myio);
		while (pipes[i] != NULL)
		{
			if (pipes[i + 1] == NULL)
				my_end_pipe(myio);
			pid = exec_command_ior(pipes[i], env, myio[0], myio[1]);
			if (!swapio(pipefd, myio))
				return (my_free_array(pipes) && 0);
			i = i + 1;
		}
		waitpid(pid, NULL, 0);
		return (my_free_array(pipes) && 1);
	}
	return (0);
}
