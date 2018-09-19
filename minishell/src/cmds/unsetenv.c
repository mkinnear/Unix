/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:04:40 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:47:48 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stringmy.h"
#include "arraymy.h"
#include "minishell1.h"

int		command_unsetenv(char **argv, char ***env)
{
	if (argv[1] != NULL)
		*env = my_unsetenv(argv[1], *env);
	else
		my_puterror("unsetenv: Too few arguments.\n");
	return (1);
}
