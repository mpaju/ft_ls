#include "ft_ls.h"

int	init_structures(struct s_file *sfile)
{
	//if (!(sfile = ft_lstnew(sfile, sizeof(t_file))))
	//	return (0);
	
	if (!(sfile = (t_file *)malloc(sizeof(t_file))))
			return (0);
	
	if (!(sfile->filepath = (char *)malloc(sizeof(char) * 256)))
		return (0);
	if (!(sfile->time = (time_t *)malloc(sizeof(char) * 256)))
		return (0);
	if (!(sfile->name = (char *)ft_memalloc(sizeof(char) * 256)))
		return (0);
	return (1);
}

int main(int ac, const char **av)
{
	t_flag			flags;
	t_file			*filelist;

	filelist = NULL;
	check_empty_arg(ac, av);
	process_args(ac, av, &flags, &filelist);
	print_invalid_files(&flags, &filelist);
	// siin peaks nuud failinimed ka prinditud olema + errorid vale nime puhul
	ft_ls(&flags, &filelist);

	return (0);
}
