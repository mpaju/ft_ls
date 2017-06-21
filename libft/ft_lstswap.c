#include "libft.h"

int	ft_lstswap(t_list *lst, t_list *prev)
{
	t_list	*tmp;
	if (!(lst) || !(prev))
		return (0);
	prev->next = lst->next;
	tmp = lst->next;
	lst->next = tmp->next;
	tmp->next = lst;
	return (1);
}
