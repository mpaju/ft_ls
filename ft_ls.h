/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 13:58:16 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 15:01:32 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>

# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/acl.h>
# include "libft/libft.h"

# define FLAG(x) (x == 'l' || x == 'a' || x == 'r' || x == 'R' || x == 't')
# define BUFFSIZE 1024
# define SIX_MONTHS_SEC 16000000

typedef struct		s_flag {
	char			flag_l;
	char			flag_a;
	char			flag_r;
	char			flag_ur;
	char			flag_t;
	char			single_dir;
	char			first_line;
	int				userlen;
	int				grouplen;
}					t_flag;

typedef struct		s_dir {
	char			*name;
	char			*bname;
	char			*path;
	char			*link;
	int				error_nr;
	time_t			time;
	struct stat		stat;
	struct s_dir	*subfiles;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_file {
	char			*filepath;
	char			*name;
	time_t			*time;
	struct s_file	*next;
}					t_file;

void	ft_ls(t_flag *flags, t_file **filelist);
void	check_empty_arg(int ac, const char **av);
void	first_sort(const char *av, t_file **filelist);
t_dir	*free_tdir_and_return_next(t_dir *item);
char	*get_basename(char *name);
char	*get_filename(char *path, char *name);
char	*get_pathname(char *name);
int		get_args(int ac, const char **av, t_flag *flags, t_dir *dirlist);
void	get_dir_data(t_flag *flags, t_dir **arglist);
int		has_lower_alpha_value(char *str1, char *str2);
void	insert_last_pos(t_dir **diritem, t_dir **arglist);
int		is_modified_later(int val1, int val2);

void	print_type(mode_t mode);
void	print_total_blocks(t_dir *item);
void	print_rights(mode_t mode);
void	print_ftype_and_rights(t_dir *item);
void	print_linkcount(t_dir *item);
void	print_username(t_flag *flags, t_dir *item);
void	print_groupname(t_flag *flags, t_dir *item);
void	print_filesize(t_dir *item);
void	print_modtime(t_dir *item);
void	print_filename(t_dir *item);
void	print_link_data(t_dir *item);
void	print_long_format(t_flag *flags, t_dir *item);

void	print_and_remove_normal_files(t_flag *flags, t_dir **arglist);
void	print_arglist(t_flag *flags, t_dir **arglist);
void	print_invalid_files(t_flag *flags, t_file **filelist);
void	print_long_format(t_flag *flags, t_dir *item);
void	print_single_dir(t_flag *flags, t_dir **arglist);
void	print_tdir_items(t_flag *flags, t_dir **arglist);
void	print_type(mode_t mode);
void	process_args(int ac, const char **av, t_flag *flags, t_file **filelist);
void	process_flags(const char *av, t_flag *flags);
void	reverse_tdir_list(t_dir **arglist);
void	sort_by_name(t_dir **item, t_dir **list);
void	sort_by_time(t_dir **diritem, t_dir **arglist);
void	sort_filelist_into_arglist(t_flag *flags, t_file **filelist, \
	t_dir **arglist);
void	tfile_add_first(t_file *newitem, t_file **filelist);
void	tfile_add_after(t_file *newitem, t_file *filelist);
void	tfile_add_last(t_file *newitem, t_file *filelist);
t_dir	*tdirnew(t_flag *flags, char *name);
t_file	*tfilenew(char *name);
void	wrong_flag(const char *av);
#endif
