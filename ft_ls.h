#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
typedef struct		s_file {
	char			*filepath;
	char			*name;
	char			*time;
	struct s_file	*next;
}					t_file;

const char	*find_args(int ac, const char **av);
#endif
