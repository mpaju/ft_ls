#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;
	if (!lst || !f)
		return ;
	while (true)
	{
		if (lst == NULL)
			return ;
		tmp = lst->next;
		f(lst);
		lst = tmp;
	}
}