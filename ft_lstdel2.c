#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL)
		return ;
	while (1)
	{
		if (*alst == NULL)
			return ;
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		**alst = NULL;
		*alst = tmp;
	}
}
