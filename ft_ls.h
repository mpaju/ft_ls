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
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/acl.h>
# include "libft/libft.h"

# define FLAG(x) (x == 'l' || x == 'a' || x == 'r' || x == 'R' || x == 't')
# define PATHBUF 1024

typedef struct		s_flag {
	char			flag_l;
	char			flag_a;
	char			flag_r;
	char			flag_R;
	char			flag_t;
	char			not_first_line;
}					t_flag;

typedef struct		s_dir {
	char			*name;
	char			*path;
	time_t			time;
	struct s_dir	*subdir;
	struct s_dir	*filelist;
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
void	print_invalid_files(t_flag *flags, t_file **filelist);
void	print_normal_files(t_file **filelist);
void	first_sort(const char *av, t_file **filelist);
int		get_args(int ac, const char **av, t_flag *flags, t_dir *dirlist);
int		has_lower_alpha_value(char *str1, char *str2);
void	insert_last_pos(t_dir **diritem, t_dir **arglist);
int		is_modified_later(int val1, int val2);
t_dir	*tdirnew(char *name, time_t time);
t_file	*tfilenew(char *name);
void	process_args(int ac, const char **av, t_flag *flags, t_file **filelist);
void	process_flags(const char *av, t_flag *flags);
void	reverse_tdir_list(t_dir **arglist);
void	sort_filelist_into_arglist(t_flag *flags, t_file **filelist, t_dir **arglist);
void	tfile_add_first(t_file *newitem, t_file **filelist);
void	tfile_add_after(t_file *newitem, t_file *filelist);
void	tfile_add_last(t_file *newitem, t_file *filelist);
void	wrong_flag(const char *av);
#endif
