int		process_args(int ac, const char **av, t_flag *flags, t_dir *dirlist)
{
	int			i;
	struct stat	dirstat;
	time_t		time;
	t_dir		*newdir;
	t_flag		flags;

	i = 1;
	av++;
	while (*av[0] == '-' && i < ac)
	{
		process_flags(*av, flags);
		av++;
		i++;
		if (*av == '\0')
			break;
	}
	//process_dirs
	if ((lstat(*av, &dirstat)) == -1)
		perror(*av);
		// ei tea kas tuleb oige error, ilmselt peaks olema mingi ls: " " jne
}