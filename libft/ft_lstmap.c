#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp_list;

	if (!lst || !f)
		return (NULL);
	if (!(tmp = f(lst)))
		return (NULL);
	tmp_list = tmp;
	while (1)
	{
		if (!(tmp->next = f(lst->next)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
		if (lst->next == NULL)
			return (tmp_list);
	}
	return (NULL);
}