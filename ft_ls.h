#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
struct			s_file {
	char		*filepath;
	char		name[256];
	struct stat	*statbuf;
}				t_file;

const char	*find_args(int ac, const char **av);
#endif
