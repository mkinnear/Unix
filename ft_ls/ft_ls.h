/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <mkinnear@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:08:17 by mkinnear          #+#    #+#             */
/*   Updated: 2018/07/12 07:33:06 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "libft/libft.h"

struct stat				stat1;
struct dirent			*direct2;

typedef struct stat		t_stat;
typedef struct dirent	t_dir;

typedef struct			s_exp
{
	char				*d_name;
	char				*time_date;
	time_t				real_time;
	off_t				size;
	struct group		*group;
	struct passwd		*user;
	nlink_t				nlink;
	gid_t				id;
	char				perm[11];
}						t_exp;

typedef struct			s_file
{
	DIR					*file;
	char				full_path[PATH_MAX];
}						t_file;

typedef	struct			s_flags
{
	int					ls;
	int					l;
	int					a;
	int					r;
	int					rr;
	int					t;
	int					c_dir;
}						t_flags;

typedef struct			s_data
{
	t_exp				info;
	t_flags				flags;
	struct s_data		*next;
}						t_data;

typedef struct			s_recurse
{
	char				*dir;
	struct s_recurse	*next;
}						t_rec;

t_rec					*new_rec(char *path);
t_rec					*add_rec(t_rec *head, char *path);
t_rec					*dynamic_alloc(t_rec *head, char *path);
char					*create_path(char *pathway, char *curr_dir);
void					looper(t_rec *head);
void					free_lst(t_data **data);
void					add_to_lst(t_data **data, t_exp info);
int						ft_strcmp(const char *s1, const char *s2);
t_data					*lst_swap(t_data *p1, t_data *p2);
t_data					*lst_sort_ascii(t_data *data);
t_data					*lst_sort_time(t_data *data);
void					ft_init_flags(t_flags *flags);
void					ft_strmode(t_stat stat, t_exp *info);
void					formatdate(char **str, time_t val);
void					add_info(t_exp *info, t_dir *dir, t_stat stat);
t_data					*reverse_lst(t_data *data);
void					init_flags(t_flags *flags);
void					arg_reader(int argc, char **argv, t_flags *flags);
void					arg_solver(t_data **data, t_data **tmp);
void					vertical_print(t_data **data);
void					horizontal_print(t_data **data);
void					rec_ver_print(t_data **data);
void					recursion(char *path);
void					relocate(t_exp *info, t_dir **dir, t_stat *stat,
								t_data **data);
void					recursion1(char **pathway, char *path, t_rec **head,
								t_exp *info);
void					relax(t_data *data, int argc, char **argv);
void					lets_print(t_data *tmp);

#endif
