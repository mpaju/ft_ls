/*
process_dirs(ac, av, dirlist, flags)
dec	dirstat;

if ((stat(*av, &dirstat)) == -1)
	perror(*av);
else if (type = file)
	mingi filelisti?
else
	lukka dirlisti av ja dirstatist aeg, dirlisti jaoks vaja eraldi funci
nuud sorditud dirlist, lahme tagasi main funci
opendir(av)

vb peaks siin printima file nimed?


*/

/*
dirlisti func(dirlist, newdir, flagid ka)
votab dirlist + newdiri ette
if flag-t
	sort_time(dirlist, newdir)
	insertdir(&dirlist, newdir, &sort_time)
else
	sort_alpha(sama teema)
	insertdir(dirlist, newdir, &sort_alpha)

if flag-r
	lukka reversi

*/

/*
sort_time(**dirlist, newdir)
	t_dir	*prev;

	prev = NULL;
	while (*dirlist)
	{
		if (((sort_by_time(*dirlist, newdir) > 0))) //vajab debuggimist
		{
			if (prev == NULL)
			{
				pigem listaddback, front jne
				// siia normilt debugi vaja
				newdir->next = *dirlist;
				dirlist = &newdir;
				return
			}
			else
			{
				newdir->next = prev->next;
				prev->next = newdir;
				return
			}
		}
		prev = *dirlist;
		*dirlist = (*dirlist)->next;
	}
}
*/


/*
insertdir(dirlist, newdir, *f())

*/