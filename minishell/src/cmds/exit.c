/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:03:44 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:46:27 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arraymy.h"
#include "stringmy.h"
#include "minishell1.h"

int		command_exit(char **argv, char **env)
{
	int		status;

	status = 0;
	if (argv[1] != NULL)
		status = my_getnbr(argv[1]);
	my_free_array(argv);
	my_free_array(env);
	exit(status);
	return (1);
}
