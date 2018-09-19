/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:02:50 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:45:57 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stringmy.h"
#include "arraymy.h"
#include "minishell1.h"

int		command_env(char **argv, char ***env)
{
	if (argv[1] != NULL)
		my_puterror("Sorry, but env didn't suppose any arguments.\n");
	else
		my_print_array(*env);
	return (1);
}
