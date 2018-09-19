/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringmy.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:00:38 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/15 01:56:18 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGMY_H
# define STRINGMY_H

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_puterror(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int n);
int		my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
int		my_strncmp(char *str1, char *str2, int n);
int		my_getnbr(char *str);
int		my_strcmp(char *s1, char *s2);
char	*merge_strings(char *str, char *plus, int n);

#endif
