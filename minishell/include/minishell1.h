/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:03:51 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:55:52 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL1_H
# define MINISHELL1_H

int		exec_command_ior(char *cmd, char ***env, int idf, int odf);
int		exec_command_pipe(char *cmd, char ***env);
int		exec_cmds_by_order(char *cmd, char ***env);
int		execute_command(char *command, char ***env, int two, int one);
int		manage_options(int argc, char **argv);
char	*get_bin_path(char *filename, char **env);
char	*get_home_dir(char **env);
char	**my_parse_args(char *str, char **env);
int		my_getenv(char *name, char **env);
char	**my_setenv(char *name, char *value, char **env);
char	**my_unsetenv(char *name, char **env);
int		command_exit(char **argv, char **env);
int		command_setenv(char **argv, char ***env);
int		command_unsetenv(char **argv, char ***env);
int		command_cd(char **argv, char ***env);
int		command_env(char **argv, char ***env);

#endif
