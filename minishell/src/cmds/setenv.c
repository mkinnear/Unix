/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:04:07 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:47:13 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arraymy.h"
#include "stringmy.h"
#include "minishell1.h"

int		command_setenv(char **argv, char ***env)
{
	if (argv[1] != NULL)
	{
		if (argv[2] != NULL)
			*env = my_setenv(argv[1], argv[2], *env);
		else
			*env = my_setenv(argv[1], "", *env);
	}
	else
		my_puterror("setenv: Too few arguments.\n");
	return (1);
}
